package com.engineersk.grocerylistapp.Activities;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.engineersk.grocerylistapp.R;

public class DetailsActivity extends AppCompatActivity implements View.OnClickListener {

    private TextView itemNameDet;
    private TextView quantityDet;
    private TextView dateDet;
    private Button editButton;
    private Button deleteButton;
    private Bundle bundle;
    private int groceryId;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_details);

        itemNameDet=findViewById(R.id.itemNameDet);
        quantityDet=findViewById(R.id.quantityDet);
        dateDet=findViewById(R.id.dateAddedDet);
        editButton=findViewById(R.id.editItemDet);
        deleteButton=findViewById(R.id.deleteItemDet);

        editButton.setOnClickListener(DetailsActivity.this);
        deleteButton.setOnClickListener(DetailsActivity.this);

        bundle=getIntent().getExtras();

        if(bundle != null){
            itemNameDet.setText(bundle.getString("name"));
            quantityDet.setText(bundle.getString("quantity"));
            dateDet.setText(bundle.getString("date"));
            groceryId=bundle.getInt("id");
        }
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.editItemDet:
                break;

            case R.id.deleteItemDet:
                break;
        }
    }
}
