# just like in c++ to set min value we use `INT_MIN` and `INT_MAX` what we use in js

* so in js we use  `Number.MIN_SAFE_INTEGER` to set a variable to the smallest safe integer value
* or if you want the smallest possible number in JavaScript (even beyond safe integers) then we can  use `-Infinity`

    ```js
    let minValue = Number.MIN_SAFE_INTEGER;
    console.log(minValue); // -9007199254740991

    let minValue1 = -Infinity;
    console.log(minValue1); // -Infinity
    ```

* similarly for maximum we can use  `Number.MAX_SAFE_INTEGER` to set a variable to the maximum safe integer value
* or if you want the maximum possible number in JavaScript (even beyond safe integers) then we can  use `Infinity` or `+Ifinity`

    ```js
    let maxValue = Number.MAX_SAFE_INTEGER;
    console.log(maxValue); // 9007199254740991
    let maxValue1 = Infinity;
    console.log(maxValue1); // Infinity
    ```
