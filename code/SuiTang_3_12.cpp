class StudentGrade {
private:
    int studentId;       // 学号
    float* scores;       // 指向一维浮点型数组的指针（课程成绩）
    int courseCount;     // 课程门数

public:
    // 构造函数
    StudentGrade(int id, int courses);
    
    // 复制构造函数
    StudentGrade(const StudentGrade& other);
    
    // 析构函数
    ~StudentGrade();
    
    // 修改学生第i门课程成绩的函数
    void modifyScore(int i, float score);
    
    // 返回学生最高成绩函数
    float getHighestScore() const;
    
    // 返回学生平均成绩函数
    float getAverageScore() const;
    
    // 返回学生不及格课程门数函数
    int getFailedCourseCount() const;
    
    // 返回学生第i门课程成绩的函数
    float getScore(int i) const;
    
    // 显示学生成绩
    void displayGrades() const;
};

// 构造函数实现
StudentGrade::StudentGrade(int id, int courses) {
    studentId = id;
    courseCount = courses;
    scores = new float[courseCount]; 
    
    for (int i = 0; i < courseCount; i++) {
        scores[i] = 0.0;
    }
}

// 复制构造函数实现
StudentGrade::StudentGrade(const StudentGrade& other) {
    studentId = other.studentId;
    courseCount = other.courseCount;
    scores = new float[courseCount]; 
    
    // 复制成绩
    for (int i = 0; i < courseCount; i++) {
        scores[i] = other.scores[i];
    }
}

// 析构函数实现
StudentGrade::~StudentGrade() {
    delete[] scores;  
}

// 修改学生第i门课程成绩的函数
void StudentGrade::modifyScore(int i, float score) {
    if (i >= 0 && i < courseCount) {
        scores[i] = score;
    } else {
        cout << "课程编号无效！" << endl;
    }
}

// 返回学生最高成绩函数
float StudentGrade::getHighestScore() const {
    if (courseCount <= 0) return 0.0;
    
    float max = scores[0];
    for (int i = 1; i < courseCount; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}

// 返回学生平均成绩函数
float StudentGrade::getAverageScore() const {
    if (courseCount <= 0) return 0.0;
    
    float sum = 0.0;
    for (int i = 0; i < courseCount; i++) {
        sum += scores[i];
    }
    return sum / courseCount;
}

// 返回学生不及格课程门数函数
int StudentGrade::getFailedCourseCount() const {
    int count = 0;
    for (int i = 0; i < courseCount; i++) {
        if (scores[i] < 60.0) {
            count++;
        }
    }
    return count;
}

// 返回学生第i门课程成绩的函数
float StudentGrade::getScore(int i) const {
    if (i >= 0 && i < courseCount) {
        return scores[i];
    } else {
        cout << "课程编号无效！" << endl;
        return -1.0;  
    }
}

// 显示学生成绩
void StudentGrade::displayGrades() const {
    cout << "学号: " << studentId << endl;
    cout << "课程成绩: ";
    for (int i = 0; i < courseCount; i++) {
        cout << scores[i];
        if (i < courseCount - 1) {
            cout << ", ";
        }
    }
}
