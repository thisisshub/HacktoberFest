import 'package:flutter/material.dart';

import '../models/transaction.dart';
import './transaction_item.dart';

class TransactionList extends StatelessWidget {
  final List<Transaction> transactions;
  final Function deleteTx;

  TransactionList(this.transactions, this.deleteTx);

  @override
  Widget build(BuildContext context) {
    print('build() TransactionList');
    return transactions.isEmpty
        ? LayoutBuilder(builder: (ctx, constraints) {
            return Column(
              children: <Widget>[
                Text(
                  'No transactions added yet!',
                  style: Theme.of(context).textTheme.title,
                ),
                const SizedBox(
                  height: 20,
                ),
                Container(
                    height: constraints.maxHeight * 0.6,
                    child: Image.asset(
                      'assets/images/waiting.png',
                      fit: BoxFit.cover,
                    )),
              ],
            );
          })
        : // ListView.builder( //CHANGED ONLY TO DEAL WITH KEYS
        ListView(children: [
            //itemBuilder: (ctx, index) {
            //return
            ...transactions
                .map((tx) => TransactionItem(
                      key: ValueKey(tx
                          .id), //unlike UniqueKey() vk doesnot recalculate a random val
                      //but wraps a non changing indetifier provided by us
                      transaction: tx,
                      deleteTx: deleteTx,
                    ))
                .toList()
          ]
            //itemCount: transactions.length,
            );
  }
}
