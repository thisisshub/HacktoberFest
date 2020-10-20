import 'package:flutter/material.dart';
import '../screen/category_meals_screen.dart';

class CategoryItem extends StatelessWidget {
  final String title;
  final Color color;
  final String id;

  CategoryItem(this.title, this.color, this.id);

  void selectCategory(BuildContext ctx) {
    //NOW WILL USE NAMED ROUTES
    //Navigator.of(ctx).push(MaterialPageRoute(
    //builder: (_) {
    //return CategoryMealsScreen(id,title); // push this widget as a page on top of stack thatis as top screen
    //},
    //)); //handle wrapper for the new page

    Navigator.of(ctx).pushNamed(CategoryMealsScreen.routeName, arguments: {
      'id': id,
      'title': title,
    });
  }

  @override
  Widget build(BuildContext context) {
    return InkWell(
      //ripple effect with gesturedetector for tap on screen
      onTap: () => selectCategory(context), //changing pages
      splashColor: Theme.of(context).primaryColor,
      borderRadius: BorderRadius.circular(15),
      child: Container(
        padding: const EdgeInsets.all(15),
        child: Text(
          title,
          style: Theme.of(context).textTheme.title,
        ),
        //color: color,
        decoration: BoxDecoration(
          gradient: LinearGradient(
            colors: [
              color.withOpacity(0.7),
              color,
            ],
            begin: Alignment.topLeft, //direction
            end: Alignment.bottomRight,
          ),
          borderRadius: BorderRadius.circular(15),
        ),
      ),
    );
  }
}
