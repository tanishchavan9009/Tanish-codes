# 🌾 Farmer Market Crop Price Prediction System

An interactive, Object-Oriented web and cloud application designed to empower farmers and agricultural stakeholders with data-driven crop price forecasting, market decision-making tools, interactive historical price visualizations, and strategic selling advice.

---

## 📌 Project Overview

Agricultural market volatility often leaves farmers vulnerable to selling their harvest below fair market rates. The **Farmer Market Crop Price Prediction System** provides a centralized digital platform that leverages **Object-Oriented Programming (OOP)** paradigms to calculate price projections, estimate farm returns, and offer recommendations on the best time and price to sell agricultural produce.

---

## ✨ Key Features

- **🔮 Smart Crop Price Prediction (OOP Engine):** Uses an object-oriented `Crop` class to compute next-cycle projected market rates for major crops (Wheat, Rice, Cotton, Sugarcane).
- **📊 Strategic Sell Advice Engine:** Compares local buyer bids against APMC benchmark prices using the `SellAdvisor` class, providing actionable strategies (*Sell Now*, *Fair Price*, *Hold Produce*, or *Reject Offer*).
- **📈 Interactive Multi-Year Price Trend Chart:** Dynamic interactive charts powered by **Plotly** and **Chart.js**, enabling users to view and filter historical crop price trajectories from **2000 to 2025**.
- **👨‍🌾 Farmer Profit Estimator:** Instantiates a `Farmer` class model to estimate baseline farm returns, yield in quintals, and gross earnings based on registered landholding area in acres.
- **📍 APMC Market Location Hub:** Compares demand trends and price premiums across major agricultural market hubs (Pune, Mumbai, Nashik).
- **🌦 Weather & Agro-Climatic Indicators:** Displays real-time soil, moisture, and seasonal condition factors influencing harvest cycles.

---

## 🏛 Object-Oriented Programming (OOP) Architecture

The core business logic is implemented following strict OOP design in both Python (`app.py`) and JavaScript (`index.html`):

### 1. `Crop` Class
Encapsulates crop attributes and forecasting algorithms:
```python
class Crop:
    def __init__(self, name: str, base_price: float, demand: str, image_url: str):
        self.name = name
        self.base_price = base_price
        self.demand = demand
        self.image_url = image_url

    def get_prediction(self, boost_percentage: float = 15.0) -> float:
        return round(self.base_price * (1 + (boost_percentage / 100.0)), 2)
```

### 2. `Farmer` Class
Models farmer acreage, yield predictions, and net profitability:
```python
class Farmer:
    def __init__(self, name: str, land_acres: float, crop: Crop):
        self.name = name
        self.land_acres = float(land_acres)
        self.crop = crop

    def get_estimated_yield(self) -> float:
        yield_map = {"Wheat": 18.0, "Rice": 22.0, "Cotton": 10.0, "Sugarcane": 350.0}
        return round(self.land_acres * yield_map.get(self.crop.name, 15.0), 2)

    def get_estimated_net_profit(self) -> float:
        return round(self.land_acres * 15000.0, 2)
```

### 3. `SellAdvisor` Class
Evaluates trader bids against benchmark rates to generate decision advice:
```python
class SellAdvisor:
    def __init__(self, current_price: float, offered_price: float):
        self.current_price = current_price
        self.offered_price = offered_price

    def get_advice(self) -> dict:
        # Analyzes price spread and returns status & actionable strategy
```

---

## 🛠️ Technology Stack

| Component | Technology |
| :--- | :--- |
| **Cloud Application** | Streamlit (Python) |
| **Data & Visualizations** | Pandas, Plotly Express & Graph Objects |
| **Static Web App** | HTML5, CSS3, JavaScript (ES6+), Chart.js |
| **Deployment Platform** | Streamlit Community Cloud / GitHub |

---

## 📂 Project Structure

```
crop_prediction/
├── app.py            # Streamlit Cloud application
├── requirements.txt  # Python package dependencies
├── index.html        # Complete standalone web application (HTML/JS/CSS)
└── README.md         # Full project documentation & deployment guide
```

---

## 🚀 How to Run Locally

### Option A: Run Streamlit App
1. Install requirements:
   ```bash
   pip install -r requirements.txt
   ```
2. Launch the Streamlit web dashboard:
   ```bash
   streamlit run app.py
   ```
3. Open `http://localhost:8501` in your browser.

### Option B: Open Static Web App
Double click [`index.html`](file:///c:/Users/tanis/OneDrive/Desktop/Tanish%20codes/crop_prediction/index.html) to open directly in any web browser.

---

## 🌐 How to Deploy on Streamlit Cloud (Free)

Follow these simple steps to deploy online:

1. **Push your code to GitHub**:
   ```bash
   git add .
   git commit -m "Add Streamlit app and requirements for deployment"
   git push origin main
   ```
2. **Go to Streamlit Community Cloud**:
   - Visit [share.streamlit.io](https://share.streamlit.io/) and sign in with your GitHub account.
3. **Create a New App**:
   - Click **"New app"**.
   - Select your repository (`tanishchavan9009/Tanish-codes` or your fork).
   - Set **Branch** to `main`.
   - Set **Main file path** to `crop_prediction/app.py`.
4. **Click "Deploy!"**:
   - Streamlit will automatically read `requirements.txt`, install dependencies, and publish your live app URL (e.g. `https://crop-prediction-xxxx.streamlit.app`).

---

## 🔮 Future Roadmap

- 🤖 **Machine Learning Integration:** Train regression models (Random Forest / XGBoost / LSTM) on historical APMC datasets.
- 📡 **Live Mandi API Connection:** Fetch real-time market prices from open government APIs (Agmarknet).
- 🌐 **Multi-Language Support:** Regional language localization (Hindi, Marathi, etc.).
