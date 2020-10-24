package com.engineersk.grocerylistapp.Activities;

import android.os.Bundle;

import com.engineersk.grocerylistapp.Data.DatabaseHandler;
import com.engineersk.grocerylistapp.Model.Grocery;
import com.engineersk.grocerylistapp.UI.RecyclerViewAdapter;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.engineersk.grocerylistapp.R;

import java.util.ArrayList;
import java.util.List;

public class ListActivity extends AppCompatActivity {
    private RecyclerView recyclerView;
    private RecyclerViewAdapter recyclerViewAdapter;
    private List<Grocery> groceryList;
    private List<Grocery> listItems;
    private DatabaseHandler databaseHandler;
    private EditText groceryItem;
    private EditText quantity;
    private Button saveButton;
    private AlertDialog.Builder alertDialogBuilder;
    private AlertDialog alertDialog;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Add new Grocery Item and Quantity ", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();

                popUpDialog();
            }
        });

        setRecyclerView();
        updateList();

    }

    private void popUpDialog(){

        View view = getLayoutInflater().inflate(R.layout.popup, null);

        alertDialogBuilder = new AlertDialog.Builder(this);
        alertDialogBuilder.setView(view);

        alertDialog = alertDialogBuilder.create();
        alertDialog.show();

        groceryItem = view.findViewById(R.id.groceryItemID);
        quantity = view.findViewById(R.id.groceryQtyID);
        saveButton = view.findViewById(R.id.save_buttonID);

        saveButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //ToDo: save to database

                if(!groceryItem.getText().toString().isEmpty()
                        && !quantity.getText().toString().isEmpty()){

                    saveGroceryToDB(view);
                    updateList();
                    alertDialog.dismiss();
                }else{
                    Snackbar.make(view, "Enter a grocery item and quantity",
                            Snackbar.LENGTH_SHORT).show();
                }




            }
        });

    }

    private void saveGroceryToDB(View v){
        databaseHandler=new DatabaseHandler(this);
        Grocery grocery=new Grocery();

        grocery.setName(groceryItem.getText().toString());
        grocery.setQuantity(quantity.getText().toString());

        databaseHandler.addGrocery(grocery);
        databaseHandler.close();

        Snackbar.make(v, "New item added successfully", Snackbar.LENGTH_LONG)
                .setAction("Action", null).show();

    }

    private void setRecyclerView(){
        recyclerView=findViewById(R.id.RecyclerViewID);
        recyclerView.setHasFixedSize(true);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        databaseHandler = new DatabaseHandler(this);
    }

    private void updateList(){


        groceryList = new ArrayList<>();
        listItems = new ArrayList<>();

        groceryList = databaseHandler.getAllGroceries();

        if(groceryList != null){
            for (Grocery g:groceryList){
                Grocery grocery = new Grocery();
                grocery.setName(g.getName());
                grocery.setQuantity("Qty: "+g.getQuantity());
                grocery.setDateItemAdded("Date Added: "+ g.getDateItemAdded());
                grocery.setId(g.getId());

                listItems.add(grocery);
            }
        }

        recyclerViewAdapter = new RecyclerViewAdapter(this, listItems);
        recyclerView.setAdapter(recyclerViewAdapter);
        recyclerViewAdapter.notifyDataSetChanged();


    }
}
