import 'package:flutter/material.dart';
import 'package:check_my_news/constants/theme.dart';
import 'package:check_my_news/screens/homeScreen.dart';

class SplashScreen extends StatefulWidget {
  @override
  _SplashScreenState createState() => _SplashScreenState();
}

class _SplashScreenState extends State<SplashScreen> {
  @override
  void initState() {
    super.initState();
    Future.delayed(Duration(seconds: 3)).then((value) async {
      Navigator.pushReplacement(
          context,
          MaterialPageRoute(
              builder: (BuildContext context) =>
                  HomeScreen(title: 'Check My News')));
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Column(
        crossAxisAlignment: CrossAxisAlignment.center,
        mainAxisAlignment: MainAxisAlignment.center,
        mainAxisSize: MainAxisSize.max,
        children: [
          Container(
            width: double.infinity,
            height: deviceHeight(context) - 150,
            alignment: Alignment.center,
            child: Image.asset(
              'assets/n.png',
              width: 80,
              height: 80,
            ),
          ),
          Text(
            'Hot news every day',
          )
        ],
      ),
    );
  }
}
