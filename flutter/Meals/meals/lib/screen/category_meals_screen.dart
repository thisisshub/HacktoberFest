import 'package:flutter/material.dart';
import'../models/meal.dart';
import '../widgets/meal_item.dart';


class CategoryMealsScreen extends StatefulWidget {
  static const routeName = '/categories-meals';

  final List<Meal> availableMeals;

  CategoryMealsScreen(this.availableMeals);

  @override
  _CategoryMealsScreenState createState() => _CategoryMealsScreenState();
}

class _CategoryMealsScreenState extends State<CategoryMealsScreen> {
  @override

  String categoryTitle;
  List<Meal> displayedMeals;
  var _loadedInitData=false;

  void initState() { //it runs even before our widget is fully created..so no cntx
    //cannot work for any context involved
    super.initState();
  }
//VIDEO 175 REFER


  @override //runs before build
  void didChangeDependencies() { //will be called when the state is triggered
    if (!_loadedInitData){
      final routeArgs =
        ModalRoute.of(context).settings.arguments as Map<String, String>;
    categoryTitle = routeArgs['title'];
    final categoryId = routeArgs['id'];
    displayedMeals = widget.availableMeals.where((meal) {
      return meal.categories.contains(
          categoryId); //will return only the meals belonging to that category
    }).toList();
    _loadedInitData=true;

    }
    super.didChangeDependencies();
  }

  void _removeMeal(String mealId){//update the list and remove the 
    setState(() {
      displayedMeals.removeWhere((meal) => meal.id== mealId);

    });

  }

  
  Widget build(BuildContext context) {
    

    return Scaffold(
      body: ListView.builder(
        itemBuilder: (ctx, index) {
          return MealItem(
              id: displayedMeals[index].id ,
              title: displayedMeals[index].title,
              imageUrl: displayedMeals[index].imageUrl,
              duration: displayedMeals[index].duration,
              complexity: displayedMeals[index].complexity,
              affordability: displayedMeals[index].affordability,
              //removeItem: _removeMeal,
              );
              
        },
        itemCount: displayedMeals.length,
      ),
      appBar: AppBar(
        title: Text(categoryTitle),
      ),
    );
  }
}
