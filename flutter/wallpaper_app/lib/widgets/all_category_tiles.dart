import 'package:awesome_wallpaper/screens/search_results_screen.dart';
import 'package:flutter/material.dart';

class AllCategoryTiles extends StatelessWidget {
  final imageurl, name;

  AllCategoryTiles({this.imageurl, this.name});

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: () {
        Navigator.of(context).push(MaterialPageRoute(
            builder: (context) => SearchReasults(
                  search: name,
                )));
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
                width: 170,
                height: 250,
              ),
            ),
            Container(
              alignment: Alignment.center,
              width: 170,
              height: 250,
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
