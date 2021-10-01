import 'package:awesome_wallpaper/widgets/all_category_tiles.dart';
import 'package:flutter/material.dart';

class AllCategoryList extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Scaffold(
        body: Padding(
          padding: EdgeInsets.all(10),
          child: GridView(
            gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(
                crossAxisCount: 3,
                mainAxisSpacing: 3,
                crossAxisSpacing: 3,
                childAspectRatio: 0.7),
            children: [
              AllCategoryTiles(
                  name: "PARK",
                  imageurl:
                      "https://images.pexels.com/photos/2233501/pexels-photo-2233501.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
              AllCategoryTiles(
                  name: "CANDY",
                  imageurl:
                      "https://images.pexels.com/photos/1289363/pexels-photo-1289363.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
              AllCategoryTiles(
                  name: "WAR",
                  imageurl:
                      "https://images.pexels.com/photos/264146/pexels-photo-264146.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
              AllCategoryTiles(
                  name: "CAMERA",
                  imageurl:
                      "https://images.pexels.com/photos/1728163/pexels-photo-1728163.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
              AllCategoryTiles(
                  name: "FRUITS",
                  imageurl:
                      "https://images.pexels.com/photos/1435735/pexels-photo-1435735.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
              AllCategoryTiles(
                  name: "FOOD",
                  imageurl:
                      "https://images.pexels.com/photos/315755/pexels-photo-315755.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
              AllCategoryTiles(
                  name: "BED",
                  imageurl:
                      "https://images.pexels.com/photos/1841149/pexels-photo-1841149.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
              AllCategoryTiles(
                  name: "ARTIST",
                  imageurl:
                      "https://images.pexels.com/photos/45258/ballet-production-performance-don-quixote-45258.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
              AllCategoryTiles(
                  name: "MOON",
                  imageurl:
                      "https://images.pexels.com/photos/861443/pexels-photo-861443.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
              AllCategoryTiles(
                  name: "THINK",
                  imageurl:
                      "https://images.pexels.com/photos/6384/woman-hand-desk-office.jpg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
              AllCategoryTiles(
                  name: "LOVE",
                  imageurl:
                      "https://images.pexels.com/photos/3371269/pexels-photo-3371269.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
              AllCategoryTiles(
                  name: "SUCCESS",
                  imageurl:
                      "https://images.pexels.com/photos/6945/sunset-summer-golden-hour-paul-filitchkin.jpg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
              AllCategoryTiles(
                  name: "WORK",
                  imageurl:
                      "https://images.pexels.com/photos/380769/pexels-photo-380769.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
              AllCategoryTiles(
                  name: "CATS",
                  imageurl:
                      "https://images.pexels.com/photos/1741205/pexels-photo-1741205.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
              AllCategoryTiles(
                  name: "BABY",
                  imageurl:
                      "https://images.pexels.com/photos/3969272/pexels-photo-3969272.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500"),
            ],
          ),
        ),
      ),
    );
  }
}
