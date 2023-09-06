import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
          appBar: AppBar(
            title: const Text('EOS BASIC'),
            centerTitle: true,
            leading: Icon(Icons.dehaze),
            actions: [Icon(Icons.settings_outlined)],
          ),
          body: SafeArea(
              child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Image.asset('assets/eos_logo.png', width: 300, height: 300)
            ],
          ))),
    );
  }
}
