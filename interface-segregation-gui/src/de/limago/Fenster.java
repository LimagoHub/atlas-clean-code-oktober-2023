package de.limago;

import java.awt.*;
import java.awt.event.*;


public class Fenster extends Frame {


    public Fenster()  {

        setSize(300, 300);
        Button button = new Button("Drück mich");
        button.addActionListener(e->ausgabe());
        add(button);

    }

    private void ausgabe() {
        System.out.println("Button wurde gedrückt");
    }

    public static void main(String[] args) {

        new Fenster().setVisible(true);
    }

//    private class MyActionListener implements ActionListener {
//
//        @Override
//        public void actionPerformed(final ActionEvent e) {
//            ausgabe();
//        }
//    }

}
