import 'package:flutter/material.dart';
import '../screen/filters_screen.dart';

class MainDrawer extends StatelessWidget {
  Widget buildListTile(String title, IconData icon, Function tapHandler) {
    return ListTile(
      leading: Icon(
        icon,
        size: 26,
      ),
      title: Text(
        title,
        style: TextStyle(
          fontFamily: 'RobotoCondensed',
          fontSize: 24,
          fontWeight: FontWeight.bold,
        ),
      ),
      onTap: tapHandler,
    );
  }

  @override
  Widget build(BuildContext context) {
    return Drawer(
      child: Column(
        children: <Widget>[
          Container(
            height: 200,
            width: double.infinity,
            padding: EdgeInsets.all(20),
            alignment: Alignment.centerLeft,
            color: Theme.of(context).accentColor,
            child: Text(
              "Cooking Up!!",
              style: TextStyle(
                fontWeight: FontWeight.w900,
                fontSize: 30,
                color: Theme.of(context).primaryColor,
              ),
            ),
          ),
          SizedBox(
            height: 20,
          ),
          buildListTile(
            "Meals",
            Icons.restaurant,
            () {
              Navigator.of(context).pushReplacementNamed('/');//didnt keep the old pages nd pushed it
            },
          ),
          buildListTile(
            "Filters",
            Icons.settings,
            () {
              Navigator.of(context).pushReplacementNamed(FiltersScreen.routeName); //so we wont get a back button if there is no drawer
            },
          ),
        ],
      ),
    );
  }
}
