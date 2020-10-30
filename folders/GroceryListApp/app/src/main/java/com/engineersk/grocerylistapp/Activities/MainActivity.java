package com.engineersk.grocerylistapp.Activities;

import android.content.Intent;
import android.os.Bundle;

import com.engineersk.grocerylistapp.Data.DatabaseHandler;
import com.engineersk.grocerylistapp.Model.Grocery;
import com.engineersk.grocerylistapp.R;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.os.Handler;
import android.util.Log;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    private AlertDialog.Builder alertDialogBuilder;
    private AlertDialog alertDialog;
    private EditText groceryItem;
    private EditText groceryQuantity;
    private Button saveButton;
    private DatabaseHandler databaseHandler;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        databaseHandler=new DatabaseHandler(this);
        byPassActivity();

        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
//                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
//                        .setAction("Action", null).show();

                createPopUpDialog();
            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    private void createPopUpDialog(){
        alertDialogBuilder = new AlertDialog.Builder(this);
        View view = getLayoutInflater().inflate(R.layout.popup, null);

        groceryItem=view.findViewById(R.id.groceryItemID);
        groceryQuantity=view.findViewById(R.id.groceryQtyID);
        saveButton=view.findViewById(R.id.save_buttonID);

        alertDialogBuilder.setView(view);
        alertDialog=alertDialogBuilder.create();
        alertDialog.show();

        saveButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                //ToDo: Save to db
                //ToDo: Go to next screen
                if(!groceryItem.getText().toString().isEmpty()
                        && !groceryQuantity.getText().toString().isEmpty())
                    saveGroceryToDB(view);

            }
        });

    }

    private void saveGroceryToDB(View v){

        Grocery grocery=new Grocery();

        String groceryName = groceryItem.getText().toString();
        String groceryQty = groceryQuantity.getText().toString();

        grocery.setName(groceryName);
        grocery.setQuantity(groceryQty);

        databaseHandler.addGrocery(grocery);

        Snackbar.make(v,"Item saved", Snackbar.LENGTH_LONG).show();
        //Log.d("Item added ID: ", String.valueOf(databaseHandler.getGroceriesCount()));

        new Handler().postDelayed(
                new Runnable() {
                    @Override
                    public void run() {
                        alertDialog.dismiss();
                        Intent intent=new Intent(MainActivity.this,
                                ListActivity.class);
                        startActivity(intent);
                    }
                }, 1000);
    }

    private void byPassActivity(){

        if(databaseHandler.getGroceriesCount()>0){
            Intent intent=new Intent(MainActivity.this, ListActivity.class);
            startActivity(intent);
            finish();
        }

    }
}
