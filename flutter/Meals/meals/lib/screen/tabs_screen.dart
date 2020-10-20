import 'package:flutter/material.dart';
import 'package:meals/screen/categories_screen.dart';
import 'package:meals/screen/favourites_screen.dart';
import 'package:meals/screen/tabs_screenup.dart';
import '../widgets/main_drawer.dart';
import '../models/meal.dart';
import './categories_screen.dart';
import './favourites_screen.dart';

class TabsScreen extends StatefulWidget {
  final List<Meal> favoriteMeals;
  TabsScreen(this.favoriteMeals);

  @override
  _TabsScreenState createState() => _TabsScreenState();
}

class _TabsScreenState extends State<TabsScreen> {

  List<Map<String,Object>> _pages ;
  int _selectedPageIndex=0;

  @override
  void initState() {
    _pages=[
    {'page':CategoriesScreen(),'title':'Categories'},//here widget is available even at the pt of initialising
    {'page':FavoritesScreen(widget.favoriteMeals),'title':'Favorites'},
  ];
    super.initState();
  }

  void _selectPage(int index){
    setState(() {
      _selectedPageIndex=index;
    });

  }
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(_pages[_selectedPageIndex]['title']),
      ),
      drawer: MainDrawer(),
      body: _pages[_selectedPageIndex]['page'],
      bottomNavigationBar: BottomNavigationBar(
        onTap: _selectPage,
        backgroundColor: Theme.of(context).primaryColor,
        unselectedItemColor:Colors.white ,
        selectedItemColor: Theme.of(context).accentColor,
        currentIndex: _selectedPageIndex,
        type:BottomNavigationBarType.fixed,
        items: [
          BottomNavigationBarItem(
            backgroundColor:Theme.of(context).primaryColor ,
            icon: Icon(Icons.category),
            title: Text("Categories"),
          ),
          BottomNavigationBarItem(
            backgroundColor:Theme.of(context).primaryColor ,
            icon: Icon(Icons.favorite),
            title: Text("Favorites"),
          ),
        ],
      ),
    );
  }
}
