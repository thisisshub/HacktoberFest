import 'package:flutter/material.dart';
import './dummy_data.dart';
import './screen/favourites_screen.dart';
import './screen/filters_screen.dart';
import './screen/meal_detail_screen.dart';
import './screen/tabs_screen.dart';
import './models/meal.dart';

import './screen/category_meals_screen.dart';
import './screen/categories_screen.dart';

void main() => runApp(MyApp());

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  Map<String, bool> _filters = {
    'gluten': false,
    'lactose': false,
    'vegan': false,
    'vegetarian': false,
  };

  List<Meal> _availableMeals = DUMMY_MEALS;
  List<Meal> _favoriteMeals = [];

  void _setFilters(Map<String, bool> filterData) {
    setState(() {
      _filters = filterData;

      _availableMeals = DUMMY_MEALS.where((meal) {
        if (_filters['gluten'] && !meal.isGlutenFree) {
          //if filter is checked and the meal is not gluten free
          return false; //then dont include it
        }
        if (_filters['lactose'] && !meal.isLactoseFree) {
          //if filter is checked and the meal is not gluten free
          return false; //then dont include it
        }
        if (_filters['vegan'] && !meal.isVegan) {
          //if filter is checked and the meal is not gluten free
          return false; //then dont include it
        }
        if (_filters['vegetarian'] && !meal.isVegetarian) {
          //if filter is checked and the meal is not gluten free
          return false; //then dont include it
        }
        return true;
      }).toList();
    });
  }

  void _toggleFavorite(String mealId) {
    final existingIndex =
        _favoriteMeals.indexWhere((meal) => meal.id == mealId);
    if (existingIndex >= 0) {
      setState(() {
        _favoriteMeals.removeAt(
            existingIndex); //remove that meal from the list if it already exists as toggle
      });
    } else {
      //-1
      setState(() {
        _favoriteMeals.add(DUMMY_MEALS.firstWhere((meal) => meal.id == mealId));
      }); //first meal taht has this id is added to favs
    }
  }

  bool _isMealFavorite(String id){
    return _favoriteMeals.any((meal)=> meal.id==id); //any meal in the list in which the id is true
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'DailyMeals',
      theme: ThemeData(
        primarySwatch: Colors.pink,
        accentColor: Colors.amber,
        canvasColor: Color.fromRGBO(255, 255, 229, 1),
        fontFamily: 'Raleway',
        textTheme: ThemeData.light().textTheme.copyWith(
              body1: TextStyle(
                color: Color.fromRGBO(20, 51, 51, 1),
              ),
              body2: TextStyle(
                color: Color.fromRGBO(20, 51, 51, 1),
              ),
              title: TextStyle(
                fontSize: 20,
                fontFamily: 'RobotoCondensed',
                fontWeight: FontWeight.bold,
              ),
            ),
      ),
      //home: CategoriesScreen(), //1st screen entry
      initialRoute: '/', // already set by default
      routes: {
        //in order to handle multiple pages nav.
        '/': (ctx) => TabsScreen(_favoriteMeals),
        CategoryMealsScreen.routeName: (ctx) =>
            CategoryMealsScreen(_availableMeals),
        MealDetailScreen.routeName: (ctx) => MealDetailScreen(_toggleFavorite,_isMealFavorite),
        FiltersScreen.routeName: (ctx) => FiltersScreen(_filters, _setFilters),
      },
      onGenerateRoute: (settings) {
        print(settings.arguments);
        return MaterialPageRoute(
          builder: (ctx) => CategoriesScreen(),
        );
      }, //if we try to go to pushnamed route but its not registerd in the routes table
      onUnknownRoute: (settings) {
        return MaterialPageRoute(
          builder: (ctx) => CategoriesScreen(),
        );
      },
      //used when flutter failed to build a screen-always show something
    );
  }
}
