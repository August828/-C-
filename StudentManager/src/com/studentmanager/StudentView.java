package com.studentmanager;

import java.util.Scanner;

public class StudentView {
    Scanner sc = new Scanner(System.in);
    Student[] students = new Student[50];
    int count = 0; // 记录数组中有多少个对象
    Student[] newStudents = new Student[students.length - 1]; // 新数组，一会删除元素的时候需要将删除后剩下的元素复制到新数组中

    public void start() {
        while (true) {
            System.out.println("------------学生管理系统------------");
            System.out.println("1 添 加 学 生");
            System.out.println("2 修 改 学 生");
            System.out.println("3 删 除 学 生");
            System.out.println("4 查 看 学 生");
            System.out.println("5 退       出");
            System.out.println("请选择（1-5）：");

            int num = sc.nextInt();
            System.out.println("----------------------------------");

            switch (num) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    updateStudent();
                    break;
                case 3:
                    deleteStudent();
                    break;
                case 4:
                    findAllStudent();
                    break;
                default:
                    System.out.println("是否退出？0退出||9取消");
                    int key = sc.nextInt();
                    if (key == 0) {
                        System.out.println("使用完毕！");
                        return;
                    } else if (key == 9) {
                        break;
                    }
            }
        }
    }

    // 添加功能
    private void addStudent() {
        System.out.println("请输入学生学号：");
        int id = sc.nextInt();
        System.out.println("请输入学生姓名：");
        String name = sc.next();
        System.out.println("请输入学生年龄：");
        int age = sc.nextInt();
        System.out.println("请输入学生性别：");
        String sex = sc.next();

        Student student = new Student(id, name, age, sex);

        students[count++] = student;
        System.out.println("添加成功！");
    }

    // 修改功能
    private void updateStudent() {
        System.out.println("请您输入要修改的学生学号：");
        int id = sc.nextInt();

        int updateIndex = ArrayUtils.findIndexById(students, id, count);
        System.out.println("请您输入要修改的学生姓名：");
        String name = sc.next();
        System.out.println("请您输入要修改的学生年龄：");
        int age = sc.nextInt();
        System.out.println("请您输入要修改的学生性别：");
        String sex = sc.next();

        Student student = new Student(id, name, age, sex);
        students[updateIndex] = student;
        System.out.println("修改成功！");
    }

    // 删除功能
    private void deleteStudent() {
        System.out.println("请输入要删除的学生学号：");
        int id = sc.nextInt();

        int removeIndex = ArrayUtils.findIndexById(students, id, count);

        // 复制被删除前面一部分
        System.arraycopy(students, 0, newStudents, 0, removeIndex);
        // 复制被删除后面一部分
        System.arraycopy(students, removeIndex + 1, newStudents, removeIndex, students.length - removeIndex - 1);

        students = newStudents;
        count--;
        System.out.println("删除成功！");
    }

    // 查找功能
    private void findAllStudent() {
        System.out.println("学号" + "  " + "姓名" + " " + "年龄" + "  " + "性别");

        /*
         *  排序是防止：删除完之后重新添加之前删除的序号对应学生
         * */
        for (int j = 0; j < count - 1; j++) {
            for (int i = 0; i < count - j - 1; i++) {
                if (students[i].getId() > students[i + 1].getId()) {
                    Student temp = students[i];
                    students[i] = students[i + 1];
                    students[i + 1] = temp;
                }
            }
        }

        if (count == 0) {
            System.out.println("班级没有学生，待开班...");
        } else {
            for (int i = 0; i < count; i++) {
                System.out.println(students[i].getId() + "\t" + students[i].getName() + "\t" + students[i].getAge() + "\t" + students[i].getSex());
            }
        }
    }
}

