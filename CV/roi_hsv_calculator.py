import cv2
import numpy as np
import os
import tkinter as tk
from tkinter import filedialog

# 全局变量
drawing = False
roi_start_pt = (-1, -1)
roi_end_pt = (-1, -1)
roi_selected = False
img_bgr = None
img_hsv = None
lower_hsv = None
upper_hsv = None
min_contour_area = 0

H_PAD = 0
S_PAD = 0
V_PAD = 0

def select_roi_and_calculate_hsv(event, x, y, flags, param):
    global drawing, roi_start_pt, roi_end_pt, roi_selected, img_hsv, lower_hsv, upper_hsv

    if event == cv2.EVENT_LBUTTONDOWN:
        drawing = True
        roi_selected = False
        roi_start_pt = (x, y)
        roi_end_pt = (x, y)
        lower_hsv = None
        upper_hsv = None
        # 不再在此处销毁 Mask 窗口
        # try:
        #     cv2.destroyWindow('Mask')
        # except cv2.error:
        #     pass

    elif event == cv2.EVENT_MOUSEMOVE:
        if drawing:
            roi_end_pt = (x, y)

    elif event == cv2.EVENT_LBUTTONUP:
        drawing = False
        roi_end_pt = (x, y)
        if abs(roi_start_pt[0] - roi_end_pt[0]) > 0 and abs(roi_start_pt[1] - roi_end_pt[1]) > 0:
            roi_selected = True
            x1, y1 = roi_start_pt
            x2, y2 = roi_end_pt
            x_start, x_end = min(x1, x2), max(x1, x2)
            y_start, y_end = min(y1, y2), max(y1, y2)

            hsv_roi = img_hsv[y_start:y_end, x_start:x_end]

            if hsv_roi.size > 0:
                h_min, s_min, v_min = np.min(hsv_roi, axis=(0, 1))
                h_max, s_max, v_max = np.max(hsv_roi, axis=(0, 1))

                h_min = max(0, h_min - H_PAD)
                s_min = max(0, s_min - S_PAD)
                v_min = max(0, v_min - V_PAD)
                h_max = min(179, h_max + H_PAD)
                s_max = min(255, s_max + S_PAD)
                v_max = min(255, v_max + V_PAD)

                lower_hsv = np.array([h_min, s_min, v_min])
                upper_hsv = np.array([h_max, s_max, v_max])

                print("\n--- ROI 选择完成 ---")
                print(f"选定区域坐标: Start({x_start},{y_start}), End({x_end},{y_end})")
                print(f"计算得到的 HSV 阈值:")
                print(f"Lower: {lower_hsv}")
                print(f"Upper: {upper_hsv}")
            else:
                print("错误：选定的 ROI 无效或为空。")
                roi_selected = False
                lower_hsv = None
                upper_hsv = None
        else:
             print("选择的区域太小，请重新拖动选择。")
             roi_selected = False
             lower_hsv = None
             upper_hsv = None

# 新增：滑动条回调函数
def update_min_area(val):
    global min_contour_area
    min_contour_area = val
# ... (之前的 import 和函数定义保持不变) ...

# --- 主程序 ---

root = tk.Tk()
root.withdraw()
img_path = filedialog.askopenfilename(
    title="选择图像文件",
    filetypes=[("Image Files", "*.jpg *.jpeg *.png *.bmp *.tiff"), ("All Files", "*.*")]
)
root.destroy()

if not img_path:
    print("未选择文件，程序退出。")
    exit()

print(f"已选择图像: {img_path}")

img_bgr = cv2.imread(img_path)
if img_bgr is None:
    print(f"错误：无法加载图像 '{img_path}'")
    exit()

img_hsv = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2HSV)

window_name = f'Image: {os.path.basename(img_path)} - Drag ROI, Press Q to quit'
mask_window_name = 'Mask (Adjust Area Threshold)'
cv2.namedWindow(window_name)
cv2.setMouseCallback(window_name, select_roi_and_calculate_hsv)
cv2.namedWindow(mask_window_name)
# 注意：将 min_contour_area 的初始值传递给 createTrackbar
cv2.createTrackbar('Min Area', mask_window_name, min_contour_area, 5000, update_min_area)

print("\n说明:")
print("1. 在图像窗口中按住鼠标左键并拖动以选择一个矩形区域。")
print("2. 松开鼠标左键后，控制台将打印计算出的 HSV 阈值。")
print(f"3. '{mask_window_name}' 窗口将显示基于该阈值的掩膜。")
print(f"4. 在 '{mask_window_name}' 窗口中调整 'Min Area' 滑动条以过滤掉小区域。")
print("5. 按 'c' 键在控制台生成可复制代码片段。") # 新增说明
print("6. 按 'q' 键退出。") # 更新序号


initial_mask = np.zeros_like(img_hsv[:,:,0])

# 5. 主循环
while True:
    display_img = img_bgr.copy()

    if drawing or roi_selected:
         cv2.rectangle(display_img, roi_start_pt, roi_end_pt, (0, 255, 0), 2)

    cv2.imshow(window_name, display_img)

    current_mask_to_show = initial_mask # 默认显示空白掩码
    if lower_hsv is not None and upper_hsv is not None:
        # 计算原始掩码
        mask = cv2.inRange(img_hsv, lower_hsv, upper_hsv)

        # --- 应用最小轮廓面积过滤 ---
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        filtered_mask = np.zeros_like(mask) # 创建空白的过滤后掩码
        filtered_contours = [c for c in contours if cv2.contourArea(c) > min_contour_area]
        cv2.drawContours(filtered_mask, filtered_contours, -1, (255), thickness=cv2.FILLED)
        # --- 过滤逻辑结束 ---

        current_mask_to_show = filtered_mask # 更新要显示的掩码

    cv2.imshow(mask_window_name, current_mask_to_show)

    key = cv2.waitKey(1) & 0xFF
    if key == ord('q'):
        break
    elif key == ord('c'): # 新增：检测 'c' 键
        if lower_hsv is not None and upper_hsv is not None:
            print("\n--- 可复制代码片段 ---")
            # 使用 f-string 格式化代码，注意 numpy 数组的表示
            code_snippet = f"""
lower_hsv_from_calculator = np.array({lower_hsv.tolist()})
upper_hsv_from_calculator = np.array({upper_hsv.tolist()})
min_area_threshold = {min_contour_area} 
mask = cv2.inRange(img_hsv_new, lower_hsv_from_calculator, upper_hsv_from_calculator)

contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

filtered_mask = np.zeros_like(mask)

if contours:
    filtered_contours = [c for c in contours if cv2.contourArea(c) > min_area_threshold]
    if filtered_contours: 
            cv2.drawContours(filtered_mask, filtered_contours, -1, (255), thickness=cv2.FILLED)
"""
            print(code_snippet)
            print("--- 代码片段结束 ---\n")
        else:
            print("\n请先选择一个有效的 ROI 区域，然后再按 'c' 生成代码。\n")


cv2.destroyAllWindows()