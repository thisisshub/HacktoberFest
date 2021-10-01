import 'dart:io';
import 'dart:typed_data';

import 'package:awesome_wallpaper/models/Global.dart';
import 'package:esys_flutter_share/esys_flutter_share.dart';
import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';
import 'package:flutter_cache_manager/flutter_cache_manager.dart';
import 'package:wallpaper_manager/wallpaper_manager.dart';

// ignore: must_be_immutable
class FullImage extends StatefulWidget {
  @override
  _FullImageState createState() => _FullImageState();
}

class _FullImageState extends State<FullImage> {
  PageController pageController = PageController(initialPage: Global.index);
  bool isLoading = false;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black54,
      body: isLoading
          ? Center(
              child: CircularProgressIndicator(),
            )
          : Stack(
              fit: StackFit.expand,
              children: [
                Container(
                  height: MediaQuery.of(context).size.height,
                  child: PageView.builder(
                      controller: pageController,
                      itemCount: Global.photos.length,
                      itemBuilder: (contex, index) {
                        Global.index = index;

                        return InteractiveViewer(
                          boundaryMargin: EdgeInsets.all(100.0),
                          minScale: 0.1,
                          maxScale: 1.6,
                          child: Image.network(
                              Global.photos[Global.index].src.large2x),
                        );
                      }),
                ),
                Padding(padding: EdgeInsets.only(top: 1)),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    Expanded(
                      flex: 1,
                      child: Column(
                        mainAxisAlignment: MainAxisAlignment.end,
                        children: [
                          Padding(
                              padding: EdgeInsets.only(bottom: 10),
                              child: Row(
                                mainAxisAlignment:
                                    MainAxisAlignment.spaceEvenly,
                                children: [
                                  IconButton(
                                    icon: Icon(
                                      Icons.share,
                                      color: Colors.white,
                                      size: 35,
                                    ),
                                    onPressed: () {
                                      shareImage();
                                    },
                                    tooltip: "Share",
                                  ),
                                  IconButton(
                                    icon: Icon(Icons.wallpaper,
                                        color: Colors.white, size: 35),
                                    onPressed: () {
                                      // setWallpaper();
                                      displayModalBottomSheet(context);
                                    },
                                    tooltip: "Set Wallpaper",
                                  ),
                                ],
                              ))
                        ],
                      ),
                    ),
                  ],
                )
              ],
            ),
    );
  }

  void displayModalBottomSheet(context) {
    showModalBottomSheet(
        isDismissible: true,
        context: context,
        builder: (BuildContext bc) {
          return Container(
            child: new Wrap(
              children: <Widget>[
                ListTile(
                    leading: new Icon(Icons.lock),
                    title: new Text('Lock Screen'),
                    onTap: () {
                      setWallpaperLockScreen();
                      Navigator.of(context).pop();
                    }),
                ListTile(
                  leading: new Icon(Icons.home),
                  title: new Text('Home Screen'),
                  onTap: () {
                    setWallpaperHomeScreen();
                    Navigator.of(context).pop();
                  },
                ),
                ListTile(
                  leading: new Icon(Icons.done_all_rounded),
                  title: new Text('Home & Lock Both'),
                  onTap: () {
                    setWallpaperBoth();
                    Navigator.of(context).pop();
                  },
                ),
              ],
            ),
          );
        });
  }

  void shareImage() async {
    setState(() {
      isLoading = true;
    });
    var request = await HttpClient()
        .getUrl(Uri.parse(Global.photos[Global.index].src.large2x));
    var response = await request.close();
    Uint8List bytes = await consolidateHttpClientResponseBytes(response);

    await Share.file('ESYS AMLOG', 'amlog.jpg', bytes, 'image/jpg');
    setState(() {
      isLoading = false;
    });
  }

  Future<void> setWallpaperHomeScreen() async {
    String url = Global.photos[Global.index].src.large2x;
    int location = WallpaperManager
        .HOME_SCREEN; // or location = WallpaperManager.LOCK_SCREEN;
    var file = await DefaultCacheManager().getSingleFile(url);
    final String result =
        await WallpaperManager.setWallpaperFromFile(file.path, location);
  }

  Future<void> setWallpaperLockScreen() async {
    String url = Global.photos[Global.index].src.large2x;
    int location = WallpaperManager
        .LOCK_SCREEN; // or location = WallpaperManager.LOCK_SCREEN;
    var file = await DefaultCacheManager().getSingleFile(url);
    final String result =
        await WallpaperManager.setWallpaperFromFile(file.path, location);
  }

  Future<void> setWallpaperBoth() async {
    String url = Global.photos[Global.index].src.large2x;
    int location = WallpaperManager
        .BOTH_SCREENS; // or location = WallpaperManager.LOCK_SCREEN;
    var file = await DefaultCacheManager().getSingleFile(url);
    final String result =
        await WallpaperManager.setWallpaperFromFile(file.path, location);
  }
}
