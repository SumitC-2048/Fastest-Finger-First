# ⚡ Fastest Finger First – Arduino Project  

A **Digital Electronics Innovative Assignment** where we designed and implemented the **Fastest Finger First Game** using an Arduino UNO, 16x2 LCD display, and push buttons. This project simulates a quiz competition system with four players and automatic score tracking.  

---

## 📖 Project Overview  
The **Fastest Finger First** game allows four contestants to compete in five rounds. Each player has a dedicated button, and the system detects the **fastest button press**. Scores are updated in real-time on the LCD screen, and after five rounds, the **winner is declared automatically**.  

This project demonstrates **embedded systems programming, circuit design, and interactive digital electronics**.  

---

## 🛠️ Technologies & Components Used  

### 🔩 Hardware  
- Arduino UNO (Microcontroller)  
- 16x2 LCD Display  
- Push Buttons (4 for contestants + 2 control buttons)  
- Jumper Wires  
- Breadboard / PCB  

### 💻 Software  
- Arduino IDE (programming and uploading code)  
- Proteus (circuit simulation & testing)  
- C/C++ (Arduino programming language)  

---

## ⚙️ Features  
1. Supports **4 players** with individual buttons.  
2. **Fastest button press detection** using Arduino digital inputs.  
3. Real-time **score updates on 16x2 LCD**.  
4. Automatic **winner declaration after 5 rounds**.  
5. Reset and increment functionalities for fair gameplay.  

---

## 🔌 Pin Connections  

| Arduino Pin | Component                | Description                |
|-------------|--------------------------|----------------------------|
| 2–5         | Contestant Push Buttons  | Inputs from 4 players      |
| 8–13        | LCD Display              | Control & Data pins        |
| VCC & GND   | LCD + Buttons            | Power Supply               |
| A0–A1       | Control Buttons          | Reset & Point increment    |

---

## 🖥️ Circuit Design  
The circuit includes:  
- **Arduino UNO** connected to LCD pins (8–13).  
- **4 contestant push buttons** connected to digital pins (2–5).  
- **Control buttons** for reset and score increment.  

📌 *(circuit diagram image)*  

---
