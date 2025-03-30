// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.


/*
Input: matrix = 
[
    [1, 1, 1],
    [1, 0, 1],   here 0 is at 1st rwo and 1st coloum. (0 based indexing)
    [1, 1, 1]
]
Output: 
[
    [1, 0, 1], 
    [0, 0, 0], 
    [1, 0, 1]
]
*/
let matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]];

function setMatrixZeroBrute(matrix){
    let row,column;
    // step 1 find the row and column on which 0 is present..
    for(let i=0; i<matrix.length; i++){
        for(let j=0; j<matrix[i].length; j++){
            if(matrix[i][j]===0){
                row=i;
                column=j;
                break;
            }
        }
    }
    console.log("rwo and coloum is : ",row,column);

    // step 2  : at row and colum we got put zero in matrix..

    for(let i=0; i<matrix.length; i++){
        for(let j=0; j<matrix[i].length; j++){
            /*
            if(column===j){
                matrix[i][j]=0;
            }else if(row===i){
                matrix[i][j]=0;
            }
            */
            if(column===j || row===i){
                matrix[i][j]=0;
            }
        }
    }
    console.log(matrix);
}
setMatrixZeroBrute(matrix);

// the above code works only if there is a single 0 in entire matrix.. but in question there can be more then one 0 in input ...

/*
[
    [0, 1, 2, 0],  // 0th row and 0th column,  0th row and 3rd column..
    [3, 4, 5, 2], 
    [1, 3, 1, 5]
]

[
    [0,0,0,0]
    [0 4 5 0]
    [0 3 1 0]
]
*/
// so now the approach is i can use two array one is for the row and one is for column.. 

let matrix1 = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]];

function setMatrixZeroBrute1(matrix){
    let row=[];
    let colum=[];

    for(let i=0; i<matrix.length; i++){
        for(let j=0; j<matrix[i].length; j++){
            if(matrix[i][j]===0){
                row.push(i);
                colum.push(j);
            }
        }
    }
    console.log("row ---- > ",row);
    console.log("column ----- > ",colum);
    // step 2 : put zero on the rows...

    let index=0;
    let rowCheck=false;
    for(let i=0; i<matrix.length; i++){
        for(let j=0; j<matrix[i].length; j++){
            if(row[index]===i){
                matrix[i][j]=0;
                rowCheck=true;
            }
        }
        if(rowCheck){
            index++;
            rowCheck=false;
        }
    }
    console.log("\n\n -------- brute 1 ----------\n");
    console.log(matrix);

    index=0;
    // step 3 : assuming column as row and row as column and putting zero on each row which is basically column.
    let colLength=matrix[0].length;
    let rowLength=matrix.length;
    let colCheck=false;
    console.log("------- coumn------",colum);
    for(let i=0; i<=colLength; i++){
        for(let j=0; j<rowLength; j++){
            if(colum[index]===i){
                console.log("---------- i or colum is ",i);
                matrix[j][i]=0;
                colCheck=true;
            }
        }
        if(colCheck){
            index++;
            colCheck=false;
        }
    }
    console.log("------------- brute 1 --------- wnd ");
    console.log(matrix);
}
setMatrixZeroBrute1(matrix1);


// but the another brute approach .. is  if we are using two array row and colum then we can directly put loop and these two array and make either row or colum to 0 ..

function setMatrixZeroBrute2(matrix){
    let row=[];
    let colum=[];

    // step 1: find the row and colum at which 0 is present in matrix.
    for(let i=0; i<matrix.length; i++){
        for(let j=0; j<matrix[i].length; j++){
            if(matrix[i][j]===0){
                row.push(i);
                colum.push(j);
            }
        }
    }

    // step 2: run lloo on row array ... adn set whole row to zero mean put 0 at each colujmn.
    for (let i = 0; i < row.length; i++) {
        let r = row[i]; // Get row index
        for (let j = 0; j < matrix[0].length; j++) {
            matrix[r][j] = 0;
        }
    }

    // Step 3: Set entire columns to zero
    for (let i = 0; i < colum.length; i++) {
        let c = colum[i];
        for (let j = 0; j < matrix.length; j++) {
            matrix[j][c] = 0;
        }
    }
    console.log(matrix);
}
let matrix2 = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]];
setMatrixZeroBrute2(matrix2);



// check its optimal solution at rev time ...