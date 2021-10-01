import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

import javax.imageio.ImageIO;

public class Img2Ascii {

    private BufferedImage img;
    private double pixval;
    private PrintWriter prntwrt;
    private FileWriter filewrt;

    public Img2Ascii() {
        try {
            prntwrt = new PrintWriter(filewrt = new FileWriter("asciiart.txt", true));
        } catch (IOException ex) {
        }
    }

    public void convertToAscii(String imgname) {
        try {
            img = ImageIO.read(new File(imgname));
        } catch (IOException e) {
        }

        for (int i = 0; i < img.getHeight(); i++) {
            for (int j = 0; j < img.getWidth(); j++) {
                Color pixcol = new Color(img.getRGB(j, i));
                pixval = (((pixcol.getRed() * 0.30) + (pixcol.getBlue() * 0.59) + (pixcol.getGreen() * 0.11)));
                print(strChar(pixval));
            }
            try {
                prntwrt.println("");
                prntwrt.flush();
                filewrt.flush();
            } catch (Exception ex) {
            }
        }
    }

    public String strChar(double g) {
        String str = " ";
        if (g >= 240) {
            str = " ";
        } else if (g >= 210) {
            str = ".";
        } else if (g >= 190) {
            str = "*";
        } else if (g >= 170) {
            str = "+";
        } else if (g >= 120) {
            str = "^";
        } else if (g >= 110) {
            str = "&";
        } else if (g >= 80) {
            str = "8";
        } else if (g >= 60) {
            str = "#";
        } else {
            str = "@";
        }
        return str;
    }

    public void print(String str) {
        try {
            prntwrt.print(str);
            prntwrt.flush();
            filewrt.flush();
        } catch (Exception ex) {
        }
    }

    public static void main(String[] args) throws Exception {

        Img2Ascii obj = new Img2Ascii();
        obj.convertToAscii(args[0]);

        // read file
        FileReader fr = new FileReader("asciiart.txt");
        int i;
        while ((i = fr.read()) != -1) {
            System.out.print((char) i);

        }
        PrintWriter writer = new PrintWriter("asciiart.txt");
        writer.print("");
        writer.close();
        fr.close();
    }
}