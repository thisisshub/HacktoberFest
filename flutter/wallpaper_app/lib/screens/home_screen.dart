import 'dart:convert';

import 'package:awesome_wallpaper/models/Global.dart';
import 'package:awesome_wallpaper/models/wallpapers.dart';
import 'package:awesome_wallpaper/screens/SearchBarScreen.dart';
import 'package:awesome_wallpaper/screens/full_image_screen.dart';
import 'package:awesome_wallpaper/screens/info_screen.dart';
import 'package:awesome_wallpaper/widgets/category_title.dart';
import 'package:dynamic_theme/dynamic_theme.dart';
import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';
import 'package:http/http.dart' as http;

class HomeScreen extends StatefulWidget {
  @override
  _HomeScreenState createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  Wallpaper wallpaper;
  bool isLoading = true;

  void initState() {
    super.initState();
    getWallpapers();
  }

  void getWallpapers() async {
    //get KEY from https://www.pexels.com/api/
    var data = await http
        .get("https://api.pexels.com/v1/search?query=travelling", headers: {
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
    return Scaffold(
      appBar: AppBar(
        title: Text(
          "Awesome wallpaper",
          style: TextStyle(
            fontSize: 19,
          ),
        ),
        elevation: 0.0,
        actions: <Widget>[
          IconButton(
            icon: Icon(Icons.search),
            onPressed: () {
              Navigator.of(context).push(
                  MaterialPageRoute(builder: (context) => SearchBarScreen()));
            },
          ),
          IconButton(
            icon: Icon(Icons.brightness_6_outlined),
            onPressed: () {
              DynamicTheme.of(context).setBrightness(
                  Theme.of(context).brightness == Brightness.dark
                      ? Brightness.light
                      : Brightness.dark);
            },
          ),
          IconButton(
            icon: Icon(Icons.info_outlined),
            onPressed: () {
              Navigator.of(context).push(
                  MaterialPageRoute(builder: (context) => InfoScreen()));
            },
          ),
        ],
      ),
      body: isLoading
          ? Center(child: CircularProgressIndicator())
          : Column(
              children: [
                Padding(
                  padding: EdgeInsets.all(5),
                  child: SingleChildScrollView(
                    scrollDirection: Axis.horizontal,
                    child: Row(
                      mainAxisAlignment: MainAxisAlignment.start,
                      children: [
                        CategoryTile(
                          imageurl:
                              "https://images.pexels.com/photos/417074/pexels-photo-417074.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
                          name: "NATURE",
                        ),
                        CategoryTile(
                          imageurl:
                              "https://images.pexels.com/photos/1680140/pexels-photo-1680140.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
                          name: "BEACH",
                        ),
                        CategoryTile(
                          imageurl:
                              "https://images.pexels.com/photos/3718388/pexels-photo-3718388.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
                          name: "FLOWERS",
                        ),
                        CategoryTile(
                          imageurl:
                              "https://images.pexels.com/photos/2246476/pexels-photo-2246476.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
                          name: "CITY",
                        ),
                        GestureDetector(
                          child: CategoryTile(
                            imageurl:
                                "https://ak.picdn.net/shutterstock/videos/1028449436/thumb/1.jpg",
                            name: "MORE",
                          ),
                        ),
                      ],
                    ),
                  ),
                ),
                SingleChildScrollView(
                  child: Padding(
                    padding: EdgeInsets.all(5),
                    child: Container(
                      height: MediaQuery.of(context).size.height - 158,
                      child: GridView.builder(
                        itemCount: Global.photos.length,
                        gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(
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
    );
  }
}
