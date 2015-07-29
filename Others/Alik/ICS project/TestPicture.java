import javax.imageio.*;
import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.io.IOException;
public class TestPicture {
    public static void main(String[] args) {
        JFrame f = new JFrame();
        f.setTitle("My Panel");
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ImagePanel pp = new ImagePanel();
        pp.setLayout(new BorderLayout());
        try {
            pp.setImage(ImageIO.read(new File("C:\\Users\\Алибек\\Desktop\\ICS project\\picture.jpg")));
        } catch (IOException e) {
            e.printStackTrace();
        }
        JPanel panel = new JPanel();
        panel.setLayout(new java.awt.GridLayout());
        panel.setOpaque(false);
        JLabel label = new JLabel();
        label.setFont(new java.awt.Font("Tahoma", 0, 24));
        label.setForeground(new java.awt.Color(255, 0, 0));
        label.setText("Label");
        panel.add(label);
        JButton button = new JButton();
        button.setText("!");
        panel.add(button);
        pp.add(panel, java.awt.BorderLayout.NORTH);
        pp.setPreferredSize(new Dimension(1280, 546));
        f.add(new JScrollPane(pp));
        f.pack();
        f.setSize(1280, 546);
        f.setLocationRelativeTo(null);
        f.setVisible(true);
    }
}