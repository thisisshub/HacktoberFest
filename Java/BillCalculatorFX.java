/*
    JavaFX for creating a bill calculator. Select the number of items from the drop down list and click on create list to create the list.
    Select the item from each drop down list and enter the quantity for each element, and click on total to calculate the total.
*/
import javafx.application.Application; 
import javafx.scene.Scene; 
import javafx.scene.control.*; 
import javafx.scene.layout.*; 
import javafx.event.ActionEvent; 
import javafx.event.EventHandler; 
import javafx.scene.control.Label; 
import javafx.stage.Stage;
import javafx.scene.canvas.*; 
import javafx.scene.text.Text; 
import javafx.scene.web.*; 
import javafx.scene.Group; 
import javafx.geometry.*;
public class BillCalculatorFX extends Application{
    public void start(Stage s) {
        ComboBox b = new ComboBox(); 
        b.getItems().add("1");
        b.getItems().add("2");
        b.getItems().add("3");
        Button listBtn = new Button("Create List");
        Button totBtn = new Button("Total");
        ComboBox comboBox[] = new ComboBox[3];
        TextField numBox[] = new TextField[3];
        Text unit[] = new Text[3];
        TilePane r = new TilePane();
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.BOTTOM_CENTER);
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(25, 25, 25, 25));
        Text tot = new Text(); 
        Text disp = new Text("Total: "); 
        grid.add(totBtn,0,4);
        grid.add(disp,1,4);
        grid.add(tot,2,4);
        EventHandler<ActionEvent> event = new EventHandler<ActionEvent>() { 
            public void handle(ActionEvent e) 
            {   
                int x = Integer.parseInt((String)b.getValue()); 
                for(int i=0;i<x;i++)
                {
                    comboBox[i] = new ComboBox();
                    comboBox[i].getItems().add("Bread");
                    comboBox[i].getItems().add("Butter");
                    comboBox[i].getItems().add("Jam");
                    numBox[i] = new TextField();
                    grid.add(comboBox[i], 0, i+1);
                    grid.add(numBox[i], 1, i+1);                       
                    unit[i] = new Text();  
                    grid.add(unit[i],2,i+1);
                }
            } 
        }; 
        listBtn.setOnAction(event); 
        EventHandler<ActionEvent> totClick = new EventHandler<ActionEvent>() { 
            public void handle(ActionEvent e) 
            {   
                int n = Integer.parseInt((String)b.getValue());
                int z=10;
                int sum = 0;
                for(int i=0;i<n;i++)
                {
                    if("Bread".equals((String)comboBox[i].getValue()))
                        z=30;
                    if("Butter".equals((String)comboBox[i].getValue()))
                        z=10;
                    if("Jam".equals((String)comboBox[i].getValue()))
                        z=25;
                    int x = Integer.parseInt(numBox[i].getText()) * z;
                    unit[i].setText(String.valueOf(x));
                    sum+=x;
                }           
                tot.setText(String.valueOf(sum));     
            } 
        }; 
        grid.add(b,0,0);
        grid.add(listBtn,1,0);
        totBtn.setOnAction(totClick);
        r.getChildren().add(grid);
        Scene sc = new Scene(r, 400, 300); 
        s.setScene(sc); 
        s.show(); 
    }
    public static void main(String[] args) {        
      launch(args); 
    }
}
