package org.gui;


import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import org.controller.Controller;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;

public class CalculatorView {
    Iterator<HashMap<Character,ArrayList<String>>> iterator;
    private Controller controller;
    private String randomWord;
    private String numberToPrint;
    private ArrayList<Integer> numbers;
    private Text numbersInserted;
    public CalculatorView(Controller controller){
        this.controller = controller;
        this.randomWord = "Nastepne słowo";
        this.numbers = new ArrayList<>();
        this.numberToPrint = "";
        this.numbersInserted = new Text();
        }
    public BorderPane makeSceneGraph(){
        BorderPane root = new BorderPane();

        //Bottom
        HBox boxOut = new HBox();
        boxOut.setAlignment(Pos.CENTER);

        Text textOut = new Text(randomWord);
        textOut.setFont(new Font("Verdana",14));

        boxOut.getChildren().add(textOut);

        //Top
        HBox box = new HBox();
        box.setMinSize(600,30);

        numbersInserted.setFont(new Font("Verdana",14));
        numbersInserted.setTextAlignment(TextAlignment.LEFT);
        numbersInserted.setText(numberToPrint);

        Text sampleText = new Text();
        sampleText.setFont(new Font("Verdana",14));
        sampleText.setTextAlignment(TextAlignment.RIGHT);
        sampleText.setText("Numbers: ");

        box.getChildren().addAll(sampleText,numbersInserted);

        //Midle|Buttons
        GridPane gridPane = new GridPane();
        gridPane.setMinSize(600,500);

        gridPane.setHgap(5);
        gridPane.setVgap(5);

        HBox box1 = new HBox();
        HBox box2 = new HBox();
        HBox box3 = new HBox();

        Button button1 = new Button("1) *");
        button1.setMinSize(gridPane.getMinWidth()/3,gridPane.getMinHeight()/3);
        button1.setOnAction(actionEvent -> {
            textOut.setText(controller.nextWord());
        });
        Button button2 = new Button("2) ABC");
        button2.setOnAction(actionEvent -> {
            controller.pressedKey(2);
            numbers.add(2);
            numberToPrint += 2;
            numbersInserted.setText(numberToPrint);
        });
        button2.setMinSize(gridPane.getMinWidth()/3,gridPane.getMinHeight()/3);
        Button button3 = new Button("3) DEF");
        button3.setMinSize(gridPane.getMinWidth()/3,gridPane.getMinHeight()/3);
        button3.setOnAction(actionEvent -> {
            controller.pressedKey(3);
            numbers.add(3);
            numberToPrint += 3;
            numbersInserted.setText(numberToPrint);
        });
        box1.getChildren().addAll(button1,button2,button3);

        Button button4 = new Button("4) GHI");
        button4.setMinSize(gridPane.getMinWidth()/3,gridPane.getMinHeight()/3);
        button4.setOnAction(actionEvent -> {
            controller.pressedKey(4);
            numbers.add(4);
            numberToPrint += 4;
            numbersInserted.setText(numberToPrint);
        });

        Button button5 = new Button("5) JKL");
        button5.setMinSize(gridPane.getMinWidth()/3,gridPane.getMinHeight()/3);
        button5.setOnAction(actionEvent -> {
            controller.pressedKey(5);
            numbers.add(5);
            numberToPrint += 5;
            numbersInserted.setText(numberToPrint);;
        });

        Button button6 = new Button("6) MNO");
        button6.setMinSize(gridPane.getMinWidth()/3,gridPane.getMinHeight()/3);
        button6.setOnAction(actionEvent -> {
            controller.pressedKey(6);
            numbers.add(6);
            numberToPrint += 6;
            numbersInserted.setText(numberToPrint);
        });

        box2.getChildren().addAll(button4,button5,button6);

        Button button7 = new Button("7) PQRS");
        button7.setMinSize(gridPane.getMinWidth()/3,gridPane.getMinHeight()/3);
        button7.setOnAction(actionEvent -> {
            controller.pressedKey(7);
            numbers.add(7);
            numberToPrint += 7;
            numbersInserted.setText(numberToPrint);
        });

        Button button8 = new Button("8) TUV");
        button8.setMinSize(gridPane.getMinWidth()/3,gridPane.getMinHeight()/3);
        button8.setOnAction(actionEvent -> {
            controller.pressedKey(8);
            numbers.add(8);
            numberToPrint += 8;
            numbersInserted.setText(numberToPrint);
        });

        Button button9 = new Button("9) WXYZ");
        button9.setMinSize(gridPane.getMinWidth()/3,gridPane.getMinHeight()/3);
        button9.setOnAction(actionEvent -> {
            controller.pressedKey(9);
            numbers.add(9);
            numberToPrint += 9;
            numbersInserted.setText(numberToPrint);
        });

        box3.getChildren().addAll(button7,button8,button9);

        gridPane.addRow(0,button1,button2,button3);
        gridPane.addRow(1,button4,button5,button6);
        gridPane.addRow(2,button7,button8,button9);

        //Setup root
        root.setTop(box);
        root.setCenter(gridPane);
        root.setBottom(boxOut);

        return root;
    }
    public void previousEl(){
        controller.previousEl();
        numberToPrint = "";
        if(numbers.size() != 0) {
            numbers.remove(numbers.size() - 1);
        }
        for(int i : numbers){
            numberToPrint += i;
        }
        numbersInserted.setText(numberToPrint);
    }
}
