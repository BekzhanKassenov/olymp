import java.io.*;
import java.util.*;
import java.lang.*;

public class Main_typo extends Thread {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String s[] = new String[8];
    char nameWhite[] = {'Q', 'R', 'B', 'N', 'P', 'K'};
    char nameBlack[] = {'q', 'r', 'b', 'n', 'p', 'k'};
    char weight[] = {9, 5, 3, 3, 1, 0};


    public static void main(String args[]) {
        (new Main_typo()).run();
    }

    public void run() {
        for (int i = 0; i < 8; i++) {
            try {
                s[i] = br.readLine();
            } catch (IOException e) {
                System.exit(-1);
            }
        }
        
        int scoreWhite = 0;
        int scoreBlack = 0;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                char cc = s[i].charAt(j);

                for (int k = 0; k < 6; k++) {
                    if (nameWhite[k] == cc) {
                        scoreWhite += weight[k];
                    }
                    
                    if (nameBlack[k] == cc) {
                        scoreBlack += weight[k];
                    }
                }
            }
        }

        if (scoreWhite > scoreWhite) {
            System.out.println("White");
        } else if (scoreBlack > scoreWhite) {
            System.out.println("Black");
        } else {
            System.out.println("Draw");
        }
    }
}