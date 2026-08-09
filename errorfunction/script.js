const SP = Math.sqrt(Math.PI);


// ===============================
// ERROR FUNCTION
// ===============================

function erf(x){

    // Infinity cases

    if(x === Infinity){
        return 1;
    }

    if(x === -Infinity){
        return -1;
    }

    // Abramowitz and Stegun approximation

    const t = 1 / (1 + 0.5 * Math.abs(x));

    const tau = t * Math.exp(

        -x*x
        -1.26551223
        +1.00002368*t
        +0.37409196*t*t
        +0.09678418*t**3
        -0.18628806*t**4
        +0.27886807*t**5
        -1.13520398*t**6
        +1.48851587*t**7
        -0.82215223*t**8
        +0.17087277*t**9

    );

    return x >= 0 ? 1 - tau : tau - 1;
}



// ===============================
// COMPLEMENTARY ERROR FUNCTION
// ===============================

function erfc(x){

    if(x === Infinity){
        return 0;
    }

    if(x === -Infinity){
        return 2;
    }

    return 1 - erf(x);
}



// ===============================
// INVERSE ERROR FUNCTION
// ===============================

function erfinv(y){

    let x = 0;

    for(let i = 0; i < 30; i++){

        x = x -

        (erf(x) - y)

        /

        ((2 / SP) * Math.exp(-x*x));

    }

    return x;
}



// ===============================
// BUTTON
// ===============================

const solveBtn = document.getElementById("solveBtn");

solveBtn.addEventListener("click", solve);



// ===============================
// MAIN SOLVE FUNCTION
// ===============================

function solve(){

    const input = document
    .getElementById("xval")
    .value
    .trim();

    let x;

    // Infinity support

    if(
        input.toLowerCase() === "infinity" ||
        input.toLowerCase() === "inf" ||
        input === "∞"
    ){

        x = Infinity;

    }

    else if(
        input.toLowerCase() === "-infinity" ||
        input.toLowerCase() === "-inf" ||
        input === "-∞"
    ){

        x = -Infinity;

    }

    else{

        x = parseFloat(input);

    }


    // Validation

    if(isNaN(x)){

        alert("Please enter valid value");

        return;
    }


    const func = document
    .getElementById("func")
    .value;

    let result;


    // Solve according to function

    if(func === "erf"){

        result = erf(x);

    }

    else if(func === "erfc"){

        result = erfc(x);

    }

    else{

        result = erfinv(x);

    }


    // Display expression

    document.getElementById("expr").innerText =

        `${func}(${input})`;


    // Display result

    document.getElementById("value").innerText =

        Number(result).toPrecision(12);


    // Load sections

    loadSteps(x, func, result);

    loadSeries(x);

    loadProperties(x);


    // Smooth scroll

    document.getElementById("steps")
    .scrollIntoView({
        behavior:"smooth"
    });

}



// ===============================
// STEPWISE PROCEDURE
// ===============================

function loadSteps(x, func, result){

    const steps = document.getElementById("steps");


    // =========================
    // INFINITY CASE
    // =========================

    if(x === Infinity){

        steps.innerHTML = `

        <div class="step">

            <div class="stepNumber">1</div>

            <h3>Given Value</h3>

            <div class="code">

                x = ∞

            </div>

        </div>



        <div class="step">

            <div class="stepNumber">2</div>

            <h3>Known Property of Error Function</h3>

            <div class="code">

                lim (x → ∞) erf(x) = 1

            </div>

        </div>



        <div class="step">

            <div class="stepNumber">3</div>

            <h3>Final Answer</h3>

            <div class="code">

                erf(∞) = 1

            </div>

        </div>

        `;

        return;
    }


    // =========================
    // NORMAL SOLUTION
    // =========================

    let t = 1/(1+0.5*Math.abs(x));

    let expPart =

        -x*x
        -1.26551223
        +1.00002368*t
        +0.37409196*t*t
        +0.09678418*t**3
        -0.18628806*t**4
        +0.27886807*t**5
        -1.13520398*t**6
        +1.48851587*t**7
        -0.82215223*t**8
        +0.17087277*t**9;

    let tau = t*Math.exp(expPart);


    steps.innerHTML = `

    <div class="step">

        <div class="stepNumber">1</div>

        <h3>Formula Used</h3>

        <div class="code">

            erf(x) = (2/√π) ∫₀ˣ e^(-t²) dt

            <br><br>

            Numerical Approximation Formula:

            <br><br>

            t = 1 / (1 + 0.5|x|)

        </div>

    </div>




    <div class="step">

        <div class="stepNumber">2</div>

        <h3>Given Input</h3>

        <div class="code">

            x = ${x}

            <br><br>

            |x| = ${Math.abs(x)}

        </div>

    </div>




    <div class="step">

        <div class="stepNumber">3</div>

        <h3>Calculate t</h3>

        <div class="code">

            t = 1 / (1 + 0.5 × |${x}|)

            <br><br>

            t = 1 / (1 + ${0.5*Math.abs(x)})

            <br><br>

            t = ${t.toPrecision(12)}

        </div>

    </div>




    <div class="step">

        <div class="stepNumber">4</div>

        <h3>Substitute into Exponential Expression</h3>

        <div class="code">

            Expression =

            <br><br>

            -x² -1.26551223

            +1.00002368(t)

            +0.37409196(t²)

            +0.09678418(t³)

            -0.18628806(t⁴)

            +0.27886807(t⁵)

            -1.13520398(t⁶)

            +1.48851587(t⁷)

            -0.82215223(t⁸)

            +0.17087277(t⁹)

            <br><br>

            Expression Value

            <br><br>

            = ${expPart.toPrecision(12)}

        </div>

    </div>




    <div class="step">

        <div class="stepNumber">5</div>

        <h3>Calculate Tau</h3>

        <div class="code">

            tau = t × e^(Expression)

            <br><br>

            tau = ${t.toPrecision(12)}

            × e^(${expPart.toPrecision(12)})

            <br><br>

            tau = ${tau.toPrecision(12)}

        </div>

    </div>




    <div class="step">

        <div class="stepNumber">6</div>

        <h3>Compute Final Result</h3>

        <div class="code">

            Since x ≥ 0

            <br><br>

            erf(x) = 1 - tau

            <br><br>

            erf(${x})

            = 1 - ${tau.toPrecision(12)}

            <br><br>

            erf(${x})

            = ${Number(result).toPrecision(12)}

        </div>

    </div>




    <div class="step">

        <div class="stepNumber">7</div>

        <h3>Final Answer</h3>

        <div class="code">

            ${func}(${x}) =

            ${Number(result).toPrecision(12)}

        </div>

    </div>

    `;
}



// ===============================
// SERIES TABLE
// ===============================

function loadSeries(x){

    const series = document.getElementById("series");

    let rows = "";


    // Infinity handling

    if(x === Infinity){

        rows = `

        <tr>
            <td>∞</td>
            <td>1</td>
        </tr>

        `;
    }

    else{

        for(let i = 1; i <= 10; i++){

            let approx =

            ((2/SP) *

            (
                Math.pow(-1,i+1) *
                Math.pow(x,(2*i-1))
            )

            /
            (
                factorial(i-1) *
                (2*i-1)
            ));


            rows += `

            <tr>

                <td>${i}</td>

                <td>
                    ${approx.toPrecision(10)}
                </td>

            </tr>

            `;
        }
    }


    series.innerHTML = `

    <table class="table">

        <tr>
            <th>Iteration</th>
            <th>Approximation</th>
        </tr>

        ${rows}

    </table>

    `;
}



// ===============================
// FACTORIAL
// ===============================

function factorial(n){

    let fact = 1;

    for(let i = 1; i <= n; i++){

        fact *= i;
    }

    return fact;
}



// ===============================
// PROPERTIES
// ===============================

function loadProperties(x){

    const props = document.getElementById("properties");

    props.innerHTML = `

    <div class="step">

        <h3>Error Function Properties</h3>

        <div class="code">

            erf(0) = 0

            <br><br>

            erf(∞) = 1

            <br><br>

            erf(-∞) = -1

            <br><br>

            erf(-x) = -erf(x)

            <br><br>

            erfc(x) = 1 - erf(x)

        </div>

    </div>

    `;
}



// ===============================
// DEFAULT LOAD
// ===============================

solve();



// ===============================
// TAB SYSTEM
// ===============================

const tabs = document.querySelectorAll(".tab");

tabs.forEach(tab => {

    tab.addEventListener("click", () => {

        document.querySelectorAll(".tab")
        .forEach(t => t.classList.remove("active"));

        document.querySelectorAll(".tabContent")
        .forEach(c => c.classList.remove("active"));

        tab.classList.add("active");

        document.getElementById(tab.dataset.tab)
        .classList.add("active");

    });

});