import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'dart:io';
//custom widget
class AdaptiveFlatButton extends StatelessWidget {

  final String text;
  final Function handler;
  AdaptiveFlatButton(this.handler,this.text);

  @override
  Widget build(BuildContext context) {
    return Platform.isIOS ? CupertinoButton(child: Text(
                      text,
                      style: TextStyle(
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                    onPressed: handler,
                    //pretty similar to android.. chnage bg color
                    ) :
                  FlatButton(
                    textColor: Theme.of(context).primaryColor,
                    child: Text(
                      text,
                      style: TextStyle(
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                    onPressed: handler,
                  );
  }
}