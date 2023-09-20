import 'dart:async';
import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  var subjectList = ['국어', '수학'];
  var timeList = [0, 0, 0];
  var secList = [0, 0, 0];
  var minList = [0, 0, 0];
  var hourList = [0, 0, 0];
  var isRunning = [false, false];

  @override
  void initState() {
    // Widget 의 LifeCycle 동안 오직 1번 수행됨
    // 수행이 완료되지 않았더라도 build 함수 호출 가능
    // initState 에서도 BuildContext를 사용할 수 있다.
    super.initState();
    for (var i = 0; i < 2; i++) {
      _startTimer(i);
    }
  }

  void _startTimer(int k) {
    Timer.periodic(Duration(seconds: 1), (timer) {
      setState(() {
        if (isRunning[k]) {
          timeList[k]++;
          secList[k] = timeList[k] % 60;
          minList[k] = (timeList[k] ~/ 60) % 60;
          hourList[k] = timeList[k] ~/ 3600;
        }
        timeList[2] = timeList[0] + timeList[1];
        secList[2] = timeList[2] % 60;
        minList[2] = (timeList[2] ~/ 60) % 60;
        hourList[2] = timeList[2] ~/ 3600;
      });
    });
  }

  void _pauseTimer(int k) {
    setState(() {
      isRunning[k] = false;
    });
  }

  void _resetTimer() {
    setState(() {
      for (int i = 0; i < 3; i++) {
        timeList[i] = 0;
        isRunning[i] = false;
        secList[i] = 0;
        minList[i] = 0;
        hourList[i] = 0;
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    var secZero = ["", "", ""];
    var minZero = ["", "", ""];
    var hourZero = ["", "", ""];
    for (int j = 0; j < 3; j++) {
      if (secList[j] < 10) secZero[j] = "0";
      if (minList[j] < 10) minZero[j] = "0";
      if (hourList[j] < 10) hourZero[j] = "0";
    }

    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          backgroundColor: Colors.green,
          title: const Text('EOS BASIC'),
          centerTitle: true,
          leading: Icon(Icons.dehaze),
          actions: [Icon(Icons.settings_outlined)],
        ),
        floatingActionButton: FloatingActionButton(
          onPressed: () {},
          backgroundColor: Colors.green,
          child: Icon(Icons.add),
        ),
        body: SafeArea(
          child: Padding(
            padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 20),
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                //Image.asset('assets/eos_logo.png', width: 200, height: 200),
                InkWell(
                  onTap: () {
                    _resetTimer();
                  },
                  child: Image.asset("assets/eos_logo.png",
                      width: 200, height: 200),
                ),
                Container(
                  height: 50,
                ),
                Text(
                  "${hourZero[2]}${hourList[2]} : ${minZero[2]}${minList[2]} : ${secZero[2]}${secList[2]}",
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
                        onPressed: () {
                          if (isRunning[0]) {
                            _pauseTimer(0);
                          } else {
                            isRunning[0] = true;
                          }
                        },
                        icon: isRunning[0]
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
                        "${hourZero[0]}${hourList[0]} : ${minZero[0]}${minList[0]} : ${secZero[0]}${secList[0]}",
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
                      IconButton(
                        padding: EdgeInsets.all(0),
                        onPressed: () {
                          if (isRunning[1]) {
                            _pauseTimer(1);
                          } else {
                            isRunning[1] = true;
                          }
                        },
                        icon: isRunning[1]
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
                        "수학",
                        style: TextStyle(fontSize: 25),
                      ),
                      Text(
                        "${hourZero[1]}${hourList[1]} : ${minZero[1]}${minList[1]} : ${secZero[1]}${secList[1]}",
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
          ),
        ),
      ),
    );
  }
}
