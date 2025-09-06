package org.main;

import com.sun.javafx.scene.control.behavior.ButtonBehavior;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import javafx.stage.Stage;
import org.controller.Controller;
import org.gui.CalculatorView;

import java.util.ArrayList;


public class Main extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage){
        //Stage setup
        stage.setFullScreen(false);
        stage.setResizable(false);
        stage.setWidth(600);
        stage.setHeight(600);
        stage.setTitle("T9 NumPad");

        //Controller Setup
        Controller controller = new Controller("/Users/jakubheczko/Documents/Algo/cwiczenia_algo/projekt/t9keyboard/src/main/resources/words.json");

        CalculatorView view = new CalculatorView(controller);

        //Creating scene
        Scene scene = new Scene(view.makeSceneGraph(),Color.DARKGRAY);
        scene.setOnKeyPressed( event -> {
            if(event.getCode() == KeyCode.BACK_SPACE){
                System.out.println("BackSpace");
                view.previousEl();
            }
        });

        //Showing everything
        stage.setScene(scene);
        stage.show();
    }
}