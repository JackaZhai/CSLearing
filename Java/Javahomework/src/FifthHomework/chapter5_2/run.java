package FifthHomework.chapter5_2;

public class run {
    public static void main(String[] args) {
        FileLoadDown loadFile = new FileLoadDown();
        String url = "https://tse1-mm.cn.bing.net/th/id/OIP-C.s5BYekl6gfkEmjCLFAOGmwHaFj?rs=1&pid=ImgDetMain";
        String fileName = "图片1";
        String savePath = "/Users/Zhai/IdeaProjects/Javahomework/src/FifthHomework/chapter5_2";
        loadFile.openNetFile(url, fileName, savePath);
    }
}