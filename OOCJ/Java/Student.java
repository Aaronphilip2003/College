import java.util.*;

class Student {
    int roll;
    int erp;
    String name;

    Student() {
        roll = 0;
        erp = 0;
        name = "";
    }

    Student(String n, int r, int e) {
        name = n;
        roll = r;
        erp = e;
    }

    void showData() {
        System.out.println("Name:" + name);
        System.out.println("Roll No.:" + roll);
        System.out.println("ERP ID:" + erp);
    }

    void getData() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your name:");
        name = sc.next();
        System.out.println("Enter your Roll Number:");
        roll = sc.nextInt();
        System.out.println("Enter your ERP Number:");
        erp = sc.nextInt();
        System.out.println();

    }

    int search(Student[] s, int search) {
        int pos = -1;
        for (int i = 0; i < 3; i++) {
            if (s[i].roll == search) {
                pos = i;
                break;
            }
        }
        return pos;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int search_e;
        int pos = 0;

        Student[] s = new Student[3];

        for (int i = 0; i < 3; i++) {
            s[i] = new Student();
            s[i].getData();
        }

        System.out.println("Enter the roll number to be searched");
        search_e = sc.nextInt();

        pos = s[0].search(s, search_e);
        s[pos].showData();

    }
}