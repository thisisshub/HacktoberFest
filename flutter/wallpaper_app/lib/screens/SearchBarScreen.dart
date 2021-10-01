import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

import 'search_results_screen.dart';

class SearchBarScreen extends StatelessWidget {
  TextEditingController dataController = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Padding(
          padding: const EdgeInsets.all(5.0),
          child: Builder(
              builder: (context) => TextField(
                  controller: dataController,
                  autofocus: true,
                  decoration: InputDecoration(
                    border: InputBorder.none,
                  ),
                  style: TextStyle(
                    color: Colors.grey,
                    fontSize: 20,
                  ),
                  onSubmitted: (data) {
                    //   print(dataController.text);
                    // print(searchQuery);
                    Navigator.of(context).push(MaterialPageRoute(
                        builder: (ctx) => SearchReasults(
                              search: data,
                            )));
                  })),
        ),
      ),
    );
  }
}
