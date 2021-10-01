import 'dart:convert';

import 'package:awesome_wallpaper/models/Global.dart';
import 'package:awesome_wallpaper/models/wallpapers.dart';
import 'package:awesome_wallpaper/screens/home_screen.dart';
import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

import 'full_image_screen.dart';

class SearchReasults extends StatefulWidget {
  final String search;

  SearchReasults({this.search});

  @override
  _SearchReasultsState createState() => _SearchReasultsState(search);
}

class _SearchReasultsState extends State<SearchReasults> {
  final String search;
  bool isLoading = true;

  _SearchReasultsState(this.search);

  @override
  void initState() {
    super.initState();
    getWallpapers();
  }

  void getWallpapers() async {
    var data = await http.get("https://api.pexels.com/v1/search?query=$search",
        headers: {
          "Authorization":
              "KEY"
        });
    var jsonData = jsonDecode(data.body);
    Global.photos =
        (jsonData['photos'] as List).map((e) => Photos.fromJson(e)).toList();

    setState(() {
      isLoading = false;
    });
  }

  @override
  Widget build(BuildContext context) {
    return WillPopScope(
        onWillPop: () {
          Navigator.of(context)
              .push(MaterialPageRoute(builder: (context) => HomeScreen()));
        },
        child: Scaffold(
          body: isLoading
              ? Center(child: CircularProgressIndicator())
              : Column(
                  children: [
                    SingleChildScrollView(
                      child: Padding(
                        padding: EdgeInsets.all(5),
                        child: Container(
                          height: MediaQuery.of(context).size.height - 10,
                          child: GridView.builder(
                            itemCount: Global.photos.length,
                            gridDelegate:
                                SliverGridDelegateWithFixedCrossAxisCount(
                                    crossAxisCount: 3,
                                    mainAxisSpacing: 3,
                                    crossAxisSpacing: 3,
                                    childAspectRatio: 0.7),
                            itemBuilder: (context, index) => GestureDetector(
                              onTap: () {
                                Global.index = index;
                                Navigator.of(context).push(MaterialPageRoute(
                                    builder: (context) => FullImage()));
                              },
                              child: ClipRRect(
                                borderRadius: BorderRadius.circular(10),
                                child: Container(
                                  decoration: BoxDecoration(
                                    image: DecorationImage(
                                      fit: BoxFit.cover,
                                      image: NetworkImage(
                                          Global.photos[index].src.portrait),
                                    ),
                                  ),
                                ),
                              ),
                            ),
                          ),
                        ),
                      ),
                    ),
                  ],
                ),
        ));
  }
}
