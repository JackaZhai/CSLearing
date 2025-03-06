package FourthHomework.NO2;

public abstract class Question {
    private int chapterNumber;
    private int questionNumber;
    private String content;

    public Question(int chapterNumber, int questionNumber, String content) {
        this.chapterNumber = chapterNumber;
        this.questionNumber = questionNumber;
        this.content = content;
    }

    public int getChapterNumber() {
        return chapterNumber;
    }

    public int getQuestionNumber() {
        return questionNumber;
    }

    public String getContent() {
        return content;
    }

    public abstract void run();
}