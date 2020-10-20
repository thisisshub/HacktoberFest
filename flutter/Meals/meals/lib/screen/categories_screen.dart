import 'package:flutter/material.dart';

import '../widgets/category_item.dart';
import '../dummy_data.dart';

class CategoriesScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return  GridView(
          padding: const EdgeInsets.all(25),
          children: DUMMY_CATEGORIES
              .map(
                (catData) => CategoryItem(
                  catData.title,
                  catData
                      .color, //will return 1 item of each category one by one and make a catitem
                  catData.id,
                ),
              )
              .toList(),
          //list of data map into list of widgets
          gridDelegate: SliverGridDelegateWithMaxCrossAxisExtent(
            //sliver provides a scrollable view
            maxCrossAxisExtent: 200, //max width of tiles per row
            childAspectRatio:
                3 / 2, //sized of child elements eagrding height/w ratio
            crossAxisSpacing: 20,
            mainAxisSpacing: 20, //spacing btw cols n rows
          ),
        );
  }
}
