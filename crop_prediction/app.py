import streamlit as st
import pandas as pd
import plotly.express as px
import plotly.graph_objects as go

# ==========================================================
# PAGE CONFIGURATION & THEME STYLING
# ==========================================================
st.set_page_config(
    page_title="Farmer Market Crop Price Prediction",
    page_icon="🌾",
    layout="wide",
    initial_sidebar_state="expanded"
)

# Custom CSS for modern styling
st.markdown("""
<style>
    @import url('https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;500;600;700&display=swap');
    
    html, body, [class*="css"] {
        font-family: 'Poppins', sans-serif;
    }
    
    .main-header {
        background: linear-gradient(90deg, #1b5e20, #2e7d32, #4caf50);
        padding: 24px;
        border-radius: 16px;
        color: white;
        text-align: center;
        margin-bottom: 25px;
        box-shadow: 0 4px 15px rgba(0, 0, 0, 0.12);
    }
    
    .main-header h1 {
        color: white !important;
        font-size: 32px;
        font-weight: 700;
        margin: 0;
    }
    
    .main-header p {
        color: #e8f5e9;
        font-size: 16px;
        margin-top: 8px;
    }
    
    .crop-card {
        background: white;
        padding: 20px;
        border-radius: 14px;
        box-shadow: 0 4px 12px rgba(0,0,0,0.06);
        border: 1px solid #e0f2e1;
        transition: transform 0.2s;
        text-align: center;
    }
    
    .crop-card:hover {
        transform: translateY(-4px);
    }
    
    .metric-badge {
        display: inline-block;
        padding: 4px 12px;
        border-radius: 10px;
        font-weight: 600;
        font-size: 13px;
    }
    
    .badge-green { background: #e8f5e9; color: #2e7d32; }
    .badge-blue { background: #e3f2fd; color: #1565c0; }
    .badge-orange { background: #fff3e0; color: #e65100; }
    .badge-red { background: #ffebee; color: #c62828; }
</style>
""", unsafe_allow_html=True)


# ==========================================================
# OBJECT-ORIENTED PROGRAMMING (OOP) MODELS
# ==========================================================

class Crop:
    """Represents an agricultural crop commodity."""
    def __init__(self, name: str, base_price: float, demand: str, image_url: str):
        self.name = name
        self.base_price = base_price
        self.demand = demand
        self.image_url = image_url

    def get_prediction(self, boost_percentage: float = 15.0) -> float:
        """Calculates forecasted market rate based on demand trend."""
        return round(self.base_price * (1 + (boost_percentage / 100.0)), 2)


class Farmer:
    """Represents a registered farmer profile and acreage model."""
    def __init__(self, name: str, land_acres: float, crop: Crop):
        self.name = name
        self.land_acres = float(land_acres)
        self.crop = crop

    def get_estimated_yield(self) -> float:
        """Estimates crop harvest yield in quintals based on crop type."""
        yield_per_acre = {
            "Wheat": 18.0,
            "Rice": 22.0,
            "Cotton": 10.0,
            "Sugarcane": 350.0
        }
        return round(self.land_acres * yield_per_acre.get(self.crop.name, 15.0), 2)

    def get_estimated_gross_revenue(self) -> float:
        """Estimates gross income based on projected crop rate."""
        total_quintals = self.get_estimated_yield()
        return round(total_quintals * self.crop.get_prediction(), 2)

    def get_estimated_net_profit(self, baseline_profit_per_acre: float = 15000.0) -> float:
        """Estimates baseline net profit after input expenses."""
        return round(self.land_acres * baseline_profit_per_acre, 2)


class SellAdvisor:
    """Strategic decision advisor comparing buyer bids to APMC baseline."""
    def __init__(self, current_price: float, offered_price: float):
        self.current_price = current_price
        self.offered_price = offered_price

    def get_advice(self) -> dict:
        diff = self.offered_price - self.current_price
        diff_pct = round((diff / self.current_price) * 100, 1)

        if self.offered_price >= self.current_price + 200:
            return {
                "status": "SELL NOW",
                "badge": "badge-green",
                "message": f"Great offer! Buyer bid is ₹{diff:,.0f} (+{diff_pct}%) above APMC benchmark.",
                "recommendation": "✅ Highly Recommended: Sell your produce immediately to lock in maximum profit margins."
            }
        elif self.offered_price >= self.current_price:
            return {
                "status": "FAIR PRICE",
                "badge": "badge-blue",
                "message": f"Fair offer! Buyer bid matches current benchmark (₹{diff:,.0f} premium).",
                "recommendation": "👍 Fair Market Value: Good opportunity to sell within the next 2-3 business days."
            }
        elif self.offered_price >= self.current_price - 200:
            return {
                "status": "HOLD PRODUCE",
                "badge": "badge-orange",
                "message": f"Slightly undervalued offer (₹{abs(diff):,.0f} below benchmark, {diff_pct}%).",
                "recommendation": "⏳ Hold Produce: Wait 7–10 days. Mandi demand is projected to rebound."
            }
        else:
            return {
                "status": "REJECT OFFER",
                "badge": "badge-red",
                "message": f"Significantly undervalued offer (₹{abs(diff):,.0f} lower than benchmark).",
                "recommendation": "❌ Do Not Sell: Buyer price is unfair. Wait for next month's demand spike or check alternate APMC mandis."
            }


# ==========================================================
# DATA REPOSITORY
# ==========================================================

CROPS_DATABASE = {
    "Wheat": Crop(
        name="Wheat",
        base_price=2450.0,
        demand="High",
        image_url="https://images.unsplash.com/photo-1574323347407-f5e1ad6d020b?auto=format&fit=crop&w=500&q=80"
    ),
    "Rice": Crop(
        name="Rice",
        base_price=2369.0,
        demand="Medium",
        image_url="https://images.unsplash.com/photo-1586201375761-83865001e31c?auto=format&fit=crop&w=500&q=80"
    ),
    "Cotton": Crop(
        name="Cotton",
        base_price=7710.0,
        demand="Very High",
        image_url="https://images.unsplash.com/photo-1605000797499-95a51c5269ae?auto=format&fit=crop&w=500&q=80"
    ),
    "Sugarcane": Crop(
        name="Sugarcane",
        base_price=3200.0,
        demand="High",
        image_url="https://images.unsplash.com/photo-1598170845058-32b9d6a5da37?auto=format&fit=crop&w=500&q=80"
    )
}

# Generate 2000-2025 Historical Price Data
years_list = list(range(2000, 2026))
historical_df = pd.DataFrame({
    "Year": years_list,
    "Wheat (₹/q)": [1200 + (y - 2000) * 50 for y in years_list],
    "Rice (₹/q)": [1000 + (y - 2000) * 55 for y in years_list],
    "Cotton (₹/q)": [3000 + (y - 2000) * 180 for y in years_list],
    "Sugarcane (₹/q)": [1500 + (y - 2000) * 70 for y in years_list]
})


# ==========================================================
# SIDEBAR CONTROLS & NAVIGATION
# ==========================================================
st.sidebar.image("https://images.unsplash.com/photo-1500937386664-56d1dfef3854?auto=format&fit=crop&w=600&q=80", use_container_width=True)
st.sidebar.title("🌾 AgriMarket Hub")
st.sidebar.markdown("**Decision Support & Forecasting**")
selected_tab = st.sidebar.radio(
    "Navigate to:",
    ["📊 Dashboard Overview", "🔮 Crop Price Predictor", "💡 Smart Sell Advisor", "📈 Historical Price Trends", "👨‍🌾 Farmer Profit Estimator", "📍 APMC Mandis & Weather"]
)

st.sidebar.markdown("---")
st.sidebar.info("💡 **OOP Powered Engine**: Built with Object-Oriented JavaScript & Python design principles for maximum accuracy and scalability.")


# ==========================================================
# HEADER SECTION
# ==========================================================
st.markdown("""
<div class="main-header">
    <h1>🌾 Farmer Market Crop Price Prediction System</h1>
    <p>Smart Agro-Commodity Price Forecasting, Sell Advisory & Historical Market Trend Analysis</p>
</div>
""", unsafe_allow_html=True)


# ==========================================================
# TAB 1: DASHBOARD OVERVIEW
# ==========================================================
if selected_tab == "📊 Dashboard Overview":
    st.subheader("📌 Market Snapshot")
    
    # Summary KPI Cards
    col1, col2, col3, col4 = st.columns(4)
    with col1:
        st.metric(label="🌾 Tracked Commodities", value="4 Major Crops", delta="All Active")
    with col2:
        st.metric(label="📍 Monitored Mandis", value="3 APMC Hubs", delta="+12% Avg. Premium")
    with col3:
        st.metric(label="🌦 Harvest Suitability", value="Optimal", delta="72% Soil Moisture")
    with col4:
        st.metric(label="📈 Forecast Trend", value="Bullish (+15%)", delta="High Demand Cycle")

    st.markdown("---")
    st.subheader("🌱 Popular Agricultural Commodities")
    
    cols = st.columns(4)
    for idx, (crop_name, crop_obj) in enumerate(CROPS_DATABASE.items()):
        with cols[idx]:
            st.markdown(f"""
            <div class="crop-card">
                <img src="{crop_obj.image_url}" style="width:100%; height:140px; object-fit:cover; border-radius:10px; margin-bottom:10px;" />
                <h3 style="margin:5px 0; color:#1b5e20;">{crop_obj.name}</h3>
                <p style="margin:4px 0; font-weight:600;">MSP: ₹{crop_obj.base_price:,.0f} / q</p>
                <p style="margin:4px 0; color:#555;">Demand: <b>{crop_obj.demand}</b></p>
                <span class="metric-badge badge-green">Projected: ₹{crop_obj.get_prediction():,.0f}/q</span>
            </div>
            """, unsafe_allow_html=True)

    st.markdown("---")
    st.markdown("""
    ### 💡 Why Farmers Use This Platform
    - **🎯 Data-Driven Pricing**: Prevent distress sales by validating trader quotes against historical and seasonal patterns.
    - **⚡ Instant OOP Forecasting**: Fast client & cloud calculation models without latency.
    - **📊 Strategic Advice**: Receive actionable signals whether to sell right away, hold for 10 days, or look for alternate regional mandis.
    """)


# ==========================================================
# TAB 2: PRICE PREDICTOR
# ==========================================================
elif selected_tab == "🔮 Crop Price Predictor":
    st.subheader("🔮 Crop Market Rate Predictor (OOP Engine)")
    st.write("Calculate next-cycle projected market rates by applying demand forecasts to benchmark prices.")

    col1, col2 = st.columns([1, 1])
    with col1:
        selected_crop_name = st.selectbox("Select Crop Commodity:", list(CROPS_DATABASE.keys()))
        crop_obj = CROPS_DATABASE[selected_crop_name]
        
        custom_boost = st.slider(
            "Projected Seasonal Demand Surge (%):",
            min_value=0,
            max_value=35,
            value=15,
            help="Expected percentage price surge based on festival or post-harvest cycles."
        )
        
        predict_btn = st.button("Calculate Forecast Rate", type="primary", use_container_width=True)

    with col2:
        if predict_btn or True:
            predicted_rate = crop_obj.get_prediction(custom_boost)
            gain = predicted_rate - crop_obj.base_price
            
            st.success(f"### Forecast Summary for **{crop_obj.name}**")
            m1, m2 = st.columns(2)
            with m1:
                st.metric(label="Current Benchmark (MSP)", value=f"₹{crop_obj.base_price:,.2f} / q")
            with m2:
                st.metric(label="Forecasted Selling Rate", value=f"₹{predicted_rate:,.2f} / q", delta=f"+₹{gain:,.2f} ({custom_boost}%)")

            fig_bar = go.Figure(data=[
                go.Bar(name='Current MSP', x=[crop_obj.name], y=[crop_obj.base_price], marker_color='#2e7d32'),
                go.Bar(name='Projected Rate', x=[crop_obj.name], y=[predicted_rate], marker_color='#81c784')
            ])
            fig_bar.update_layout(
                barmode='group',
                title="Current vs Projected Price (₹ per Quintal)",
                height=260,
                margin=dict(l=20, r=20, t=40, b=20)
            )
            st.plotly_chart(fig_bar, use_container_width=True)


# ==========================================================
# TAB 3: SMART SELL ADVISOR
# ==========================================================
elif selected_tab == "💡 Smart Sell Advisor":
    st.subheader("💡 Strategic Sell Advice Engine")
    st.write("Compare the price offered by your local trader/agent against the APMC benchmark rate to get instant strategic guidance.")

    col1, col2 = st.columns([1, 1])
    with col1:
        crop_for_advice = st.selectbox("Choose Crop:", list(CROPS_DATABASE.keys()), key="sell_crop_select")
        base_rate = CROPS_DATABASE[crop_for_advice].base_price
        st.info(f"📌 Current APMC Benchmark for **{crop_for_advice}**: **₹{base_rate:,.2f} / quintal**")

        offered_rate = st.number_input(
            "Price Offered by Trader / Market (₹ / quintal):",
            min_value=500.0,
            max_value=30000.0,
            value=float(base_rate + 150.0),
            step=50.0
        )
        
        evaluate_btn = st.button("Evaluate Offer", type="primary", use_container_width=True)

    with col2:
        advisor = SellAdvisor(current_price=base_rate, offered_price=offered_rate)
        result = advisor.get_advice()

        st.markdown(f"### Strategy: <span class='metric-badge {result['badge']}'>{result['status']}</span>", unsafe_allow_html=True)
        st.markdown(f"**Analysis:** {result['message']}")
        
        if result['status'] == "SELL NOW":
            st.success(result['recommendation'])
        elif result['status'] == "FAIR PRICE":
            st.info(result['recommendation'])
        elif result['status'] == "HOLD PRODUCE":
            st.warning(result['recommendation'])
        else:
            st.error(result['recommendation'])

        # Gauge Chart for Offer evaluation
        diff_pct = ((offered_rate - base_rate) / base_rate) * 100
        fig_gauge = go.Figure(go.Indicator(
            mode = "gauge+number+delta",
            value = offered_rate,
            domain = {'x': [0, 1], 'y': [0, 1]},
            title = {'text': f"Offer vs Benchmark (₹{base_rate:,.0f})", 'font': {'size': 18}},
            delta = {'reference': base_rate, 'increasing': {'color': "green"}, 'decreasing': {'color': "red"}},
            gauge = {
                'axis': {'range': [base_rate * 0.6, base_rate * 1.4]},
                'bar': {'color': "#2e7d32"},
                'steps': [
                    {'range': [base_rate * 0.6, base_rate - 200], 'color': "#ffebee"},
                    {'range': [base_rate - 200, base_rate], 'color': "#fff3e0"},
                    {'range': [base_rate, base_rate * 1.4], 'color': "#e8f5e9"}
                ],
                'threshold': {
                    'line': {'color': "black", 'width': 4},
                    'thickness': 0.75,
                    'value': base_rate
                }
            }
        ))
        fig_gauge.update_layout(height=280, margin=dict(l=30, r=30, t=40, b=20))
        st.plotly_chart(fig_gauge, use_container_width=True)


# ==========================================================
# TAB 4: HISTORICAL TRENDS
# ==========================================================
elif selected_tab == "📈 Historical Price Trends":
    st.subheader("📈 Multi-Year Historical Price Trends (2000 - 2025)")
    st.write("Filter and explore long-term price appreciation across major crop varieties.")

    col1, col2 = st.columns([1, 3])
    with col1:
        st.write("#### ⚙️ Filters")
        year_range = st.slider(
            "Select Time Period:",
            min_value=2000,
            max_value=2025,
            value=(2010, 2025)
        )
        
        selected_crop_cols = st.multiselect(
            "Select Crops to Plot:",
            ["Wheat (₹/q)", "Rice (₹/q)", "Cotton (₹/q)", "Sugarcane (₹/q)"],
            default=["Wheat (₹/q)", "Rice (₹/q)", "Cotton (₹/q)", "Sugarcane (₹/q)"]
        )

    with col2:
        filtered_df = historical_df[(historical_df["Year"] >= year_range[0]) & (historical_df["Year"] <= year_range[1])]
        
        if selected_crop_cols:
            fig_trend = px.line(
                filtered_df,
                x="Year",
                y=selected_crop_cols,
                markers=True,
                title=f"Crop Price Trajectory ({year_range[0]} - {year_range[1]})",
                color_discrete_map={
                    "Wheat (₹/q)": "#e67e22",
                    "Rice (₹/q)": "#27ae60",
                    "Cotton (₹/q)": "#2980b9",
                    "Sugarcane (₹/q)": "#8e44ad"
                }
            )
            fig_trend.update_layout(
                yaxis_title="Price in ₹ per Quintal",
                hovermode="x unified",
                legend_title_text="Commodity",
                height=420
            )
            st.plotly_chart(fig_trend, use_container_width=True)
        else:
            st.warning("Please select at least one crop to view the graph.")

    with st.expander("📄 View Raw Historical Data"):
        st.dataframe(filtered_df, use_container_width=True)


# ==========================================================
# TAB 5: FARMER PROFIT ESTIMATOR
# ==========================================================
elif selected_tab == "👨‍🌾 Farmer Profit Estimator":
    st.subheader("👨‍🌾 Farmer Profit & Revenue Estimator (OOP Logic)")
    st.write("Simulate farm profitability and yield returns using the `Farmer` class model.")

    col1, col2 = st.columns([1, 1])
    with col1:
        farmer_name = st.text_input("Farmer Full Name:", value="Ramesh Patil")
        cultivated_crop = st.selectbox("Primary Crop Cultivated:", list(CROPS_DATABASE.keys()))
        land_size = st.number_input("Cultivation Area (in Acres):", min_value=0.5, max_value=500.0, value=5.0, step=0.5)
        
        calculate_profit_btn = st.button("Calculate Farm Returns", type="primary", use_container_width=True)

    with col2:
        crop_instance = CROPS_DATABASE[cultivated_crop]
        farmer_model = Farmer(name=farmer_name, land_acres=land_size, crop=crop_instance)
        
        est_yield = farmer_model.get_estimated_yield()
        est_revenue = farmer_model.get_estimated_gross_revenue()
        est_net_profit = farmer_model.get_estimated_net_profit()

        st.markdown(f"### 📋 Farm Summary: **{farmer_model.name}**")
        p1, p2 = st.columns(2)
        with p1:
            st.metric(label="Estimated Total Yield", value=f"{est_yield:,.1f} Quintals")
            st.metric(label="Projected Gross Revenue", value=f"₹{est_revenue:,.2f}")
        with p2:
            st.metric(label="Registered Land", value=f"{farmer_model.land_acres} Acres")
            st.metric(label="Estimated Net Baseline Profit", value=f"₹{est_net_profit:,.2f}", delta="Standard Input Model")

        st.success(f"🌾 Based on {farmer_model.land_acres} acres of **{cultivated_crop}**, expected harvest is **{est_yield:,.1f} quintals** generating projected gross returns of **₹{est_revenue:,.2f}** at forecasted rate ₹{crop_instance.get_prediction():,.0f}/q.")


# ==========================================================
# TAB 6: MANDIS & WEATHER
# ==========================================================
elif selected_tab == "📍 APMC Mandis & Weather":
    st.subheader("📍 Major APMC Mandi Locations & Premiums")
    
    mandi_cols = st.columns(3)
    with mandi_cols[0]:
        st.markdown("""
        <div class="crop-card">
            <h3>🏢 Pune APMC Market</h3>
            <p><b>Demand:</b> High</p>
            <p><b>Price Premium:</b> +15% over MSP</p>
            <span class="metric-badge badge-green">Recommended</span>
        </div>
        """, unsafe_allow_html=True)
        
    with mandi_cols[1]:
        st.markdown("""
        <div class="crop-card">
            <h3>🏢 Mumbai Wholesale Mandi</h3>
            <p><b>Demand:</b> Very High</p>
            <p><b>Price Premium:</b> +20% over MSP</p>
            <span class="metric-badge badge-orange">Highest Volume</span>
        </div>
        """, unsafe_allow_html=True)

    with mandi_cols[2]:
        st.markdown("""
        <div class="crop-card">
            <h3>🏢 Nashik Agro Hub</h3>
            <p><b>Demand:</b> Medium</p>
            <p><b>Price Premium:</b> +10% over MSP</p>
            <span class="metric-badge badge-blue">Direct Farmer Connect</span>
        </div>
        """, unsafe_allow_html=True)

    st.markdown("---")
    st.subheader("🌦 Weather & Agro-Climatic Conditions")
    
    w1, w2, w3, w4 = st.columns(4)
    with w1:
        st.metric(label="⛅ Current Weather", value="Clear Sky", delta="Good for Harvest")
    with w2:
        st.metric(label="🌱 Soil Classification", value="Black Fertile", delta="Optimal pH 7.2")
    with w3:
        st.metric(label="💧 Moisture Level", value="72%", delta="Adequate")
    with w4:
        st.metric(label="📈 Seasonal Yield Outlook", value="High (+12%)", delta="Favorable Climate")

    st.markdown("---")
    st.subheader("📞 APMC Farmer Helpdesk & Support")
    st.write("- 📧 **Email Support:** farmerhelp@agrimarket.gov.in")
    st.write("- 📱 **Kisan Call Centre (Toll Free):** 1800-180-1551 / +91 8881577000")
    st.write("- 🕒 **Helpline Timings:** Monday - Saturday (8:00 AM - 6:00 PM)")


# ==========================================================
# FOOTER
# ==========================================================
st.markdown("---")
st.markdown(
    "<div style='text-align: center; color: #666; font-size: 14px;'>"
    "🌾 <b>Farmer Market Crop Price Prediction System</b> | Built with Streamlit & Object-Oriented Python"
    "</div>",
    unsafe_allow_html=True
)
