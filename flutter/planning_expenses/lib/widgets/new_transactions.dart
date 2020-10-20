import 'dart:io';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:intl/intl.dart';

import '../widgets/adaptive_flat_button.dart';


class NewTransaction extends StatefulWidget {
  final Function addTx;

  NewTransaction(this.addTx);

  @override
  _NewTransactionState createState() => _NewTransactionState();
}

class _NewTransactionState extends State<NewTransaction> {
  final _titleController = TextEditingController();
  DateTime _selectedDate;
  final _amountController = TextEditingController();
   
  @override
  void initState() { //fetch from https
    // TODO: implement initState
    super.initState(); //super refers to parent-class(i.e is the obj of state obj extended at _newtranState..)
  }
  //inside init
  //assert is a Dart function that tests a condition and throws an error if it's not met.
  // _debugLifecycleState is a property managed by Flutter to find out in which phase the state object currently is.

  @override //refetch
  void didUpdateWidget(NewTransaction oldWidget) { //gives u old widget so u can compare for new updation
    // TODO: implement didUpdateWidget
    super.didUpdateWidget(oldWidget);
  }

  @override// clean from memory
  void dispose() {
    // TODO: implement dispose //called when the widget needs to be deleted
    super.dispose();
  }

  void _submitData() {
    if (_amountController.text.isEmpty) {
      return;
    }
    final enteredTitle = _titleController.text;
    final enteredAmount = double.parse(_amountController.text);
    if (enteredTitle.isEmpty || enteredAmount <= 0 || _selectedDate == null) {
      return; //stops func execution and below code not reached
    }

    widget.addTx(
      //.widget is used to access your prop of widget class in state class
      enteredTitle,
      enteredAmount,
      _selectedDate,
    );
    Navigator.of(context).pop();
  }

  void _presentDatePicker() {
    showDatePicker(
      context: context,
      initialDate: DateTime.now(),
      firstDate: DateTime(2020),
      lastDate: DateTime.now(),
    ).then((pickedDate) {
      if (pickedDate == null) {
        return;
      }
      setState(() {
        _selectedDate = pickedDate;
      });
    }); // app would not to wait for input
  } // since showdatepicker returns a future class which triggers when the date is actually chosen

  @override
  Widget build(BuildContext context) {
    return SingleChildScrollView(
      child: Card(
      elevation: 5,
      child: Container(
        padding: EdgeInsets.only(
          top: 10,
          left: 10,
          right: 10,
          bottom: MediaQuery.of(context).viewInsets.bottom + 10,//gives info abt anything that lapping in our view: softkeyboard
        ),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.end,
          children: <Widget>[
            
            TextField(
              decoration: InputDecoration(labelText: 'Title'),
              //onChanged: (val) {titleInput=val;},
              controller: _titleController,
              onSubmitted: (_) =>
                  _submitData(), //as inside anonymous func so ()
            ),
            TextField(
              decoration: InputDecoration(labelText: 'Amount'),
              controller: _amountController,
              //  onChanged: (val) {amountInput=val; },
              keyboardType: TextInputType.number, //when tap only no. keyboard
              onSubmitted: (_) => _submitData(),
            ),
            Container(
              height: 70,
              child: Row(
                children: <Widget>[
                  Expanded(
                    child: Text(
                      _selectedDate == null
                          ? 'No Date Chosen'
                          : 'Picked Date: ${DateFormat.yMd().format(_selectedDate)}',
                    ),
                  ),
                  AdaptiveFlatButton(_presentDatePicker ,'Choose Date'),
                ],
              ),
            ),
            RaisedButton(
              // onPressed: () {print(amountInput);print(titleInput);},
              onPressed: _submitData,
              child: Text('ADD transaction'),
              color: Theme.of(context).primaryColor,
              textColor: Theme.of(context).textTheme.button.color,
            ),
          ],
        ),
      ),
    )
    );
  }
}
