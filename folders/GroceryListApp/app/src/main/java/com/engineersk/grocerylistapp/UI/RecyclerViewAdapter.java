package com.engineersk.grocerylistapp.UI;

import android.app.AlertDialog;
import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.engineersk.grocerylistapp.Activities.DetailsActivity;
import com.engineersk.grocerylistapp.Data.DatabaseHandler;
import com.engineersk.grocerylistapp.Model.Grocery;
import com.engineersk.grocerylistapp.R;
import com.google.android.material.snackbar.Snackbar;

import java.util.List;

public class RecyclerViewAdapter extends RecyclerView.Adapter<RecyclerViewAdapter.ViewHolder> {

    private Context context;
    private List<Grocery> groceryItems;
    private AlertDialog.Builder alertDialogBuilder;
    private AlertDialog alertDialog;
    private LayoutInflater inflater;

    public RecyclerViewAdapter(Context context, List<Grocery> groceryItems) {
        this.context = context;
        this.groceryItems = groceryItems;
    }

    @NonNull
    @Override
    public RecyclerViewAdapter.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {

        View view= LayoutInflater.from(parent.getContext())
                .inflate(R.layout.list_row, parent, false);

        return new ViewHolder(view, context);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {

        Grocery grocery=groceryItems.get(position);

        holder.groceryItemName.setText(grocery.getName());
        holder.quantity.setText(grocery.getQuantity());
        holder.dateAdded.setText(grocery.getDateItemAdded());

    }

    @Override
    public int getItemCount() {
        return groceryItems.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener {

        private TextView groceryItemName;
        private TextView quantity;
        private TextView dateAdded;
        private Button editButton;
        private Button deleteButton;
        private int id;
        private DatabaseHandler groceryDBHandler;

        public ViewHolder(@NonNull View itemView, Context ctx) {
            super(itemView);

            context = ctx;

            groceryItemName = itemView.findViewById(R.id.name);
            quantity = itemView.findViewById(R.id.quantityID);
            dateAdded = itemView.findViewById(R.id.date);
            editButton = itemView.findViewById(R.id.editButtonID);
            deleteButton = itemView.findViewById(R.id.deleteButtonID);

            editButton.setOnClickListener(this);
            deleteButton.setOnClickListener(this);

            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    int position = getAdapterPosition();
                    Grocery grocery = groceryItems.get(position);

                    Intent intent = new Intent(context, DetailsActivity.class);
                    intent.putExtra("name", grocery.getName());
                    intent.putExtra("quantity", grocery.getQuantity());
                    intent.putExtra("date", grocery.getDateItemAdded());
                    intent.putExtra("id", grocery.getId());

                    context.startActivity(intent);

                }
            });
        }

        @Override
        public void onClick(View view) {
            switch (view.getId()) {
                case R.id.editButtonID:
                    editItem();
                    break;

                case R.id.deleteButtonID:
                    Grocery grocery = groceryItems.get(getAdapterPosition());
                    deleteItem(grocery.getId());
                    break;
            }
        }

        private void deleteItem(final int id) {
            alertDialogBuilder = new AlertDialog.Builder(context);

            inflater = LayoutInflater.from(context);
            View view = inflater.inflate(R.layout.confirmation_dialog, null);

            Button noButton = view.findViewById(R.id.noButtonID);
            Button yesButton = view.findViewById(R.id.yesButtonID);

            alertDialogBuilder.setView(view);
            alertDialog = alertDialogBuilder.create();
            alertDialog.show();

            noButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    alertDialog.dismiss();
                }
            });

            yesButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {

                    groceryDBHandler = new DatabaseHandler(context);
                    groceryDBHandler.deleteGroceryItem(id);
                    groceryItems.remove(getAdapterPosition());
                    notifyItemRemoved(getAdapterPosition());
                    alertDialog.dismiss();
                }
            });

        }

        private void editItem() {

            inflater = LayoutInflater.from(context);
            final View view = inflater.inflate(R.layout.popup, null);

            alertDialogBuilder = new AlertDialog.Builder(context);
            alertDialogBuilder.setView(view);

            alertDialog = alertDialogBuilder.create();
            alertDialog.show();

            final EditText groceryItem = view.findViewById(R.id.groceryItemID);
            final EditText quantity = view.findViewById(R.id.groceryQtyID);
            final TextView groceryTitle = view.findViewById(R.id.title);
            final Button saveButton = view.findViewById(R.id.save_buttonID);

            groceryTitle.setText("Edit Grocery");

            saveButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    groceryDBHandler = new DatabaseHandler(context);
                    Grocery grocery = groceryItems.get(getAdapterPosition());

                    if (!groceryItem.getText().toString().isEmpty()
                            && !quantity.getText().toString().isEmpty()) {

                        grocery.setName(groceryItem.getText().toString());
                        grocery.setQuantity(quantity.getText().toString());
                        groceryItems.set(getAdapterPosition(), grocery);
                        groceryDBHandler.updateGroceryItem(grocery);
                        notifyItemChanged(getAdapterPosition(), grocery);
                        alertDialog.dismiss();

                    } else {
                        Snackbar.make(view, "Add Grocery and Quantity",
                                Snackbar.LENGTH_LONG).show();
                    }
                }
            });

        }
    }
}
