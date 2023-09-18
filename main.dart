import 'dart:async';

import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  //
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  var _timer;
  var _time = 0;
  var _isRunning = false;
  var _stopWatch;
  @override
  void initState() {
    super.initState(); // initState class 를 가져옴
    _timer = Timer.periodic(Duration(seconds: 1),
        _updateTimer); // 이것만 추가 ( 1초에 한번씩 _updateTimer를 실행)
  }

  void _updateTimer(Timer timer) {
    setState(() {
      if (_isRunning) {
        _time++;
      }
    });
  }

  void _startTimer() {
    setState(() {
      _isRunning = true;
    });
  }

  void _pauseTimer() {
    setState(() {
      _isRunning = false;
    });
  }

  @override
  Widget build(BuildContext context) {
    var sec = (_time % 60).toString().padLeft(2, '0');
    var min = (((_time / 60).toInt()) % 60.toInt())
        .toString()
        .padLeft(2, '0'); // (_time~/60)%60
    var hour = ((_time / 3600).toInt()).toString().padLeft(2, '0');

    var secZero = "";
    var minZero = "";
    var hourZero = "";
    // if (sec < 10) secZero = "0";
    // if (min < 10) minZero = "0";
    // if (hour < 10) hourZero = "0";

    return MaterialApp(
      home: Scaffold(
          // 알아서 상중하로 나누어주는 위젯
          appBar: AppBar(
            backgroundColor: Colors.green,
            title: const Text('EOS BASIC'),
            centerTitle: true,
            leading: Icon(Icons.dehaze), // 햄버거 아이콘
            actions: [Icon(Icons.settings_outlined)], // 톱니바퀴(설정) 아이콘
          ),
          floatingActionButton: FloatingActionButton(
            // 스크롤 해도 항상 떠 있는 위젯
            onPressed: () {},
            backgroundColor: Colors.green,
            child: Icon(Icons.add), // + 표시
          ),
          body: SafeArea(
              // 휴대폰 조건에 따라 화면이 잘리지 않도록 방지
              child: Padding(
            padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 20),
            child: Column(
              // 세로정렬
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Image.asset('assets/eos_logo.png', width: 200, height: 200),
                Container(
                  height: 50,
                ),
                Text(
                  "00:00:00",
                  style: TextStyle(
                    fontSize: 35,
                    fontWeight: FontWeight.bold,
                  ),
                ),
                Container(
                  height: 50,
                ),
                Divider(
                  height: 3,
                  color: Colors.black,
                ),
                Padding(
                  padding:
                      const EdgeInsets.symmetric(horizontal: 16, vertical: 12),
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      IconButton(
                        padding: EdgeInsets.all(0),
                        onPressed: (_isRunning ? _pauseTimer : _startTimer),
                        icon: _isRunning
                            ? Icon(
                                Icons.pause_circle,
                                size: 40,
                                color: Colors.green,
                              )
                            : Icon(
                                Icons.play_circle,
                                size: 40,
                                color: Colors.green,
                              ),
                      ),
                      Text(
                        "국어",
                        style: TextStyle(fontSize: 25),
                      ),
                      Text(
                        "$hour : $min : $sec",
                        style: TextStyle(fontSize: 25),
                      ),
                    ],
                  ),
                ),
                Divider(
                  height: 3,
                  color: Colors.black,
                ),
                Padding(
                  padding:
                      const EdgeInsets.symmetric(horizontal: 16, vertical: 12),
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Icon(
                        Icons.play_circle,
                        size: 40,
                        color: Colors.green,
                      ),
                      Text(
                        "수학",
                        style: TextStyle(fontSize: 25),
                      ),
                      Text(
                        "00:00:00",
                        style: TextStyle(fontSize: 25),
                      ),
                    ],
                  ),
                ),
                Divider(
                  height: 3,
                  color: Colors.black,
                ),
              ],
            ),
          ))),
    );
  }
}
