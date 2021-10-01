import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import 'package:url_launcher/url_launcher.dart';

class InfoScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      // backgroundColor: Colors.deepPurple[900],
      appBar: AppBar(
        title: Text("About",
            style: TextStyle(color: Colors.white, fontFamily: 'Poppins')),
        // backgroundColor: Colors.deepPurple[900],
        iconTheme: IconThemeData(color: Colors.white),
        elevation: 0,
      ),
      body: Stack(
        children: <Widget>[
          Positioned(
            child: Center(
              child: Container(
                  height: MediaQuery.of(context).size.height / 1.6,
                  width: MediaQuery.of(context).size.width - 100,
                  child: Card(
                    shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(20)),
                    child: Column(
                      children: <Widget>[
                        SizedBox(
                          height: 100,
                        ),
                        Padding(
                          padding: const EdgeInsets.symmetric(horizontal: 10),
                          child: Text(
                            "App to Find Awesome wallpaper of different categories.",
                            textAlign: TextAlign.center,
                          ),
                        ),
                        SizedBox(
                          height: 40,
                        ),
                        Text("You can find the whole source code on",
                            style: TextStyle(
                                fontSize: 12, fontStyle: FontStyle.normal)),
                        Text("github.com/viralvaghela",
                            style: TextStyle(
                                fontSize: 14, fontWeight: FontWeight.bold)),
                        SizedBox(
                          height: 40,
                        ),
                        Text("Made with ❤ by",
                            style: TextStyle(
                                fontSize: 12, fontStyle: FontStyle.normal)),
                        Text("@viralvaghela",
                            style: TextStyle(
                                fontSize: 20, fontWeight: FontWeight.bold)),
                        SizedBox(
                          height: 40,
                        ),
                        Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            IconButton(
                                icon: FaIcon(FontAwesomeIcons.githubAlt),
                                onPressed: () async {
                                  if (await canLaunch(
                                      "https://github.com/viralvaghela")) {
                                    await launch(
                                        "https://github.com/viralvaghela");
                                  } else {
                                    throw 'Could not launch url';
                                  }
                                }),
                            IconButton(
                                icon: FaIcon(FontAwesomeIcons.facebookF),
                                onPressed: () async {
                                  if (await canLaunch(
                                      "https://www.facebook.com/thecodingboy")) {
                                    await launch(
                                        "https://www.facebook.com/thecodingboy");
                                  } else {
                                    throw 'Could not launch url';
                                  }
                                }),
                            IconButton(
                                icon: FaIcon(FontAwesomeIcons.twitter),
                                onPressed: () async {
                                  if (await canLaunch(
                                      "https://www.twitter.com/mrcodingboy")) {
                                    await launch(
                                        "https://www.twitter.com/mrcodingboy");
                                  } else {
                                    throw 'Could not launch url';
                                  }
                                }),
                            IconButton(
                                icon: FaIcon(FontAwesomeIcons.internetExplorer),
                                onPressed: () async {
                                  if (await canLaunch(
                                      "https://viralvaghela.github.io")) {
                                    await launch(
                                        "https://viralvaghela.github.io");
                                  } else {
                                    throw 'Could not launch url';
                                  }
                                }),
                            IconButton(
                                icon: FaIcon(FontAwesomeIcons.googlePlay),
                                onPressed: () async {
                                  if (await canLaunch(
                                      "https://play.google.com/store/apps/developer?id=viral+vaghela")) {
                                    await launch(
                                        "https://play.google.com/store/apps/developer?id=viral+vaghela");
                                  } else {
                                    throw 'Could not launch url';
                                  }
                                }),
                          ],
                        )
                      ],
                    ),
                  )),
            ),
          ),
          Align(
            alignment: Alignment.topCenter,
            child: Padding(
              padding: const EdgeInsets.symmetric(vertical: 20.0),
              child: Container(
                height: 150,
                width: 150,
                child: CircleAvatar(
                  backgroundImage: NetworkImage(
                    "https://codingboy.in/wp-content/uploads/2020/04/Coding-Boy-2.png",
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
