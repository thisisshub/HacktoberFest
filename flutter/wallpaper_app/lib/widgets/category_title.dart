import 'package:awesome_wallpaper/screens/all_category_list.dart';
import 'package:awesome_wallpaper/screens/search_results_screen.dart';
import 'package:flutter/material.dart';

class CategoryTile extends StatelessWidget {
  final imageurl, name;

  CategoryTile({this.imageurl, this.name});

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: () {
        name != "MORE"
            ? Navigator.of(context).push(MaterialPageRoute(
                builder: (context) => SearchReasults(
                      search: name,
                    )))
            : Navigator.of(context).push(
                MaterialPageRoute(builder: (context) => AllCategoryList()));
      },
      child: Container(
        padding: EdgeInsets.only(left: 5, right: 5),
        child: Stack(
          children: <Widget>[
            ClipRRect(
              borderRadius: BorderRadius.circular(15),
              child: Image.network(
                imageurl,
                fit: BoxFit.cover,
                width: 120,
                height: 50,
              ),
            ),
            Container(
              alignment: Alignment.center,
              width: 120,
              height: 50,
              decoration: BoxDecoration(
                  color: Colors.black38,
                  borderRadius: BorderRadius.circular(15)),
              child: Text(
                name,
                style: TextStyle(
                  fontFamily: 'Poppins',
                  color: Colors.white,
                  fontSize: 15,
                ),
              ),
            )
          ],
        ),
      ),
    );
  }
}
