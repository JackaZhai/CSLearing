package FourthHomework.NO2;

import java.util.*;

public class Menu {
    private Map<String, List<Question>> groupMap = new TreeMap<>();

    public void addQuestion(Question question) {
        String chapterKey = "Chapter " + question.getChapterNumber();
        groupMap.computeIfAbsent(chapterKey, k -> new ArrayList<>()).add(question);
    }

    public void displayQuestions() {
        for (Map.Entry<String, List<Question>> entry : groupMap.entrySet()) {
            System.out.println(entry.getKey() + ":");
            entry.getValue().sort(Comparator.comparingInt(Question::getQuestionNumber));
            for (Question question : entry.getValue()) {
                System.out.println("  " + question.getQuestionNumber() + ". " + question.getContent());
            }
        }
    }

    public void run() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("请选择章节号 (输入0退出):");
            displayQuestions();
            String chapterChoice = scanner.nextLine();
            if (chapterChoice.equals("0")) {
                break;
            }

            List<Question> questions = groupMap.get("Chapter " + chapterChoice);
            if (questions == null) {
                System.out.println("无效的章节号，请重新选择。");
                continue;
            }

            while (true) {
                System.out.println("请选择题目序号 (输入0返回章节选择):");
                for (Question question : questions) {
                    System.out.println("  " + question.getQuestionNumber() + ". " + question.getContent());
                }
                int questionChoice = scanner.nextInt();
                scanner.nextLine();  // 吞掉换行符
                if (questionChoice == 0) {
                    break;
                }

                Question selectedQuestion = questions.stream()
                        .filter(q -> q.getQuestionNumber() == questionChoice)
                        .findFirst()
                        .orElse(null);

                if (selectedQuestion == null) {
                    System.out.println("无效的题目序号，请重新选择。");
                } else {
                    selectedQuestion.run();
                }
            }
        }
    }

    public void runQuestion(int chapterNumber, int questionNumber) {
        List<Question> questions = groupMap.get("Chapter " + chapterNumber);
        if (questions != null) {
            for (Question question : questions) {
                if (question.getQuestionNumber() == questionNumber) {
                    question.run();
                    return;
                }
            }
        }
        System.out.println("无效的题目序号，请重新选择。");
    }
}