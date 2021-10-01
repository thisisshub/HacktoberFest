import 'package:dynamic_theme/dynamic_theme.dart';
import 'package:flutter/material.dart';

import 'screens/splash_screen.dart';

void main()=>runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return  DynamicTheme(
        defaultBrightness: Brightness.light,
        data: (brightness) => new ThemeData(
          primarySwatch: Colors.deepPurple,
          brightness: brightness,
        ),
        themedWidgetBuilder: (context, theme) {
          return new MaterialApp(
            debugShowCheckedModeBanner: false,
            theme: theme,
            home: SplashScreen()
          );
        }
    );
  }
}