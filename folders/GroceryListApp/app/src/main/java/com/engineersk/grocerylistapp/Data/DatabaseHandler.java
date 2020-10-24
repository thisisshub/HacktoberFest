package com.engineersk.grocerylistapp.Data;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

import com.engineersk.grocerylistapp.Model.Grocery;
import com.engineersk.grocerylistapp.Utils.Util;

import java.text.DateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class DatabaseHandler extends SQLiteOpenHelper {

    private Context context;
    public DatabaseHandler(@Nullable Context context) {
        super(context, Util.DATABASE_NAME, null, Util.DATABASE_VERSION);
        this.context = context;
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        String CREATE_GROCERY_TABLE = String.format("CREATE TABLE %s( " +
                        "%s INTEGER PRIMARY KEY, %s VARCHAR(150) not null, " +
                        "%s VARCHAR(15) not null, %s LONG not null);",Util.TABLE_NAME,
                Util.KEY_ID, Util.KEY_GROCERY_ITEM, Util.KEY_QUANTITY_NUMBER, Util.KEY_DATE_NAME);

        sqLiteDatabase.execSQL(CREATE_GROCERY_TABLE);

    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int oldVersion, int newVersion) {
        sqLiteDatabase.execSQL("DROP TABLE IF EXISTS " + Util.TABLE_NAME);
        onCreate(sqLiteDatabase);
    }

    public void addGrocery(Grocery grocery){
        SQLiteDatabase sqLiteDatabase=this.getWritableDatabase();

        ContentValues contentValues=new ContentValues();
        contentValues.put(Util.KEY_GROCERY_ITEM,grocery.getName());
        contentValues.put(Util.KEY_QUANTITY_NUMBER, grocery.getQuantity());
        contentValues.put(Util.KEY_DATE_NAME, System.currentTimeMillis());

        sqLiteDatabase.insert(Util.TABLE_NAME, null, contentValues);

    }

    //get a grocery item

    public Grocery getGroceryItem(int id){

        SQLiteDatabase sqLiteDatabase = this.getReadableDatabase();

        Cursor cursor = sqLiteDatabase.query(Util.TABLE_NAME,
                new String[]{Util.KEY_ID, Util.KEY_GROCERY_ITEM, Util.KEY_QUANTITY_NUMBER,
                        Util.KEY_DATE_NAME}, Util.KEY_ID+"=?",
                new String[]{String.valueOf(id)}, null, null,
                Util.KEY_DATE_NAME +" DESC", null);

        if (cursor != null)
            cursor.moveToFirst();

        Grocery myGrocery = new Grocery();
        myGrocery.setId(Integer.parseInt(cursor.getString(cursor.getColumnIndex(Util.KEY_ID))));
        myGrocery.setName(cursor.getString(cursor.getColumnIndex(Util.KEY_GROCERY_ITEM)));
        myGrocery.setQuantity(cursor.getString(cursor.getColumnIndex(Util.KEY_QUANTITY_NUMBER)));

        DateFormat dateFormat=DateFormat.getDateInstance();
        String formattedDate= dateFormat.format(
                new Date(cursor.getLong(cursor.getColumnIndex(Util.KEY_DATE_NAME))));

        myGrocery.setDateItemAdded(formattedDate);

        return myGrocery;
    }

    //get all grocery items in database
    public List<Grocery> getAllGroceries(){

        SQLiteDatabase sqLiteDatabase=this.getReadableDatabase();

        String GET_GROCERIES=String.format("SELECT * FROM %s ORDER BY %s DESC",
                Util.TABLE_NAME, Util.KEY_DATE_NAME);
        Cursor cursor=sqLiteDatabase.rawQuery(GET_GROCERIES, null);

        List<Grocery> getGroceries=new ArrayList<>();

        if(cursor != null)
            cursor.moveToFirst();

        do{

            Grocery myGrocery = new Grocery();

            myGrocery.setId(Integer.parseInt(cursor.getString(
                    cursor.getColumnIndex(Util.KEY_ID))));

            myGrocery.setName(cursor.getString(cursor.getColumnIndex(Util.KEY_GROCERY_ITEM)));

            myGrocery.setQuantity(cursor.getString(
                    cursor.getColumnIndex(Util.KEY_QUANTITY_NUMBER)));

            DateFormat dateFormat=DateFormat.getDateInstance();
            String formattedDate=dateFormat.format(
                    new Date(cursor.getLong(cursor.getColumnIndex(Util.KEY_DATE_NAME))));

            myGrocery.setDateItemAdded(formattedDate);

            getGroceries.add(myGrocery);

        }while(cursor.moveToNext());

        return getGroceries;
    }

    //update a grocery item
    public int updateGroceryItem(Grocery grocery){

        SQLiteDatabase sqLiteDatabase=this.getWritableDatabase();

        ContentValues contentValues=new ContentValues();

        contentValues.put(Util.KEY_ID, grocery.getId());
        contentValues.put(Util.KEY_GROCERY_ITEM, grocery.getName());
        contentValues.put(Util.KEY_QUANTITY_NUMBER, grocery.getQuantity());
        contentValues.put(Util.KEY_DATE_NAME, System.currentTimeMillis());

        return sqLiteDatabase.update(Util.TABLE_NAME, contentValues,
                Util.KEY_ID+"=?",new String[]{String.valueOf(grocery.getId())});

    }

    public int deleteGroceryItem(int id){
        SQLiteDatabase sqLiteDatabase=this.getWritableDatabase();

        return sqLiteDatabase.delete(Util.TABLE_NAME, Util.KEY_ID + "=?",
                new String[]{String.valueOf(id)});
    }

    public int getGroceriesCount(){
        String myQuery = "SELECT * FROM "+ Util.TABLE_NAME;
        SQLiteDatabase sqLiteDatabase = this.getReadableDatabase();

        Cursor cursor = sqLiteDatabase.rawQuery(myQuery, null);

        return cursor.getCount();
    }
}
