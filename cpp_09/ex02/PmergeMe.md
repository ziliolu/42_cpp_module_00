# **Push Swap Sorting - Step-by-Step Explanation**

## **Overview**
This document provides a detailed step-by-step breakdown of how the **Push Swap Sorting Algorithm** works. We will demonstrate the process using a large example and clearly differentiate between **pend** and **pend from recursion**.

---

## **Initial Numbers**  
**[9, 7, 15, 3, 8, 2, 11, 5, 14, 6, 20, 1, 17, 10, 12, 4, 19, 13, 18, 16]**

---

## **1️⃣ Pair Grouping and Sorting**  
We first **divide the numbers into pairs** and sort each pair individually:  

### **Before sorting:**
```
[(9,7), (15,3), (8,2), (11,5), (14,6), (20,1), (17,10), (12,4), (19,13), (18,16)]
```
### **After sorting within each pair:**
```
[(7,9), (3,15), (2,8), (5,11), (6,14), (1,20), (10,17), (4,12), (13,19), (16,18)]
```
Now, we extract the **larger** number of each pair to form the **main**, while the smaller ones go into **pend**:

**Main**: `[9, 15, 8, 11, 14, 20, 17, 12, 19, 18]`  
**Pend**: `[7, 3, 2, 5, 6, 1, 10, 4, 13, 16]`  

---

## **2️⃣ Recursive Sorting of Main**  
Now we apply **recursive sorting on the main**:

We group **main** into new pairs:
```
[(9,15), (8,11), (14,20), (17,12), (19,18)]
```
Sort each pair:
```
[(9,15), (8,11), (14,20), (12,17), (18,19)]
```
We extract the **larger** numbers again to form a **new main**, while the **smaller** ones go into **pend from recursion**:

**New Main**: `[15, 11, 20, 17, 19]`  
**Pend from recursion**: `[9, 8, 14, 12, 18]`  

We **repeat the process** on the new main:
```
[(15,11), (20,17), (19)]  ->  [(11,15), (17,20), (19)]
```

**New Main**: `[15, 20, 19]`  
**Pend from recursion**: `[11, 17]`  

Next step:
```
[(15,20), (19)] -> [(15,20), (19)]
```
**New Main**: `[20, 19]`  
**Pend from recursion**: `[15]`  

Final recursive sorting:
```
[(20,19)] -> [(19,20)]
```
**Final main sorted**: `[19, 20]`  
**Pend from recursion final**: `[15]`  

Now, we insert the elements from **pend from recursion** back into the sorted **main**.

---

## **3️⃣ Inserting Pend Elements Using Jacobsthal Sequence**  
Now, we insert elements from **pend from recursion** into the **sorted main**, using **Jacobsthal sequence** (`1, 3, 5, 11...`).

### **Step 1 - Insert 15**  
**Main**: `[19, 20]` → Insert `15` before `19`.  
New **main**: `[15, 19, 20]`  

### **Step 2 - Insert 11 and 17**  
**Main**: `[15, 19, 20]` → Insert `11` before `15`.  
New **main**: `[11, 15, 19, 20]`  
Then insert `17` before `19`.  
New **main**: `[11, 15, 17, 19, 20]`  

### **Step 3 - Insert 9, 8, 14, 12, 18**  
Each is inserted in its correct position:  
**Final main after recursion**: `[8, 9, 11, 12, 14, 15, 17, 18, 19, 20]`  

---

## **4️⃣ Insert Original Pend Elements**  
Now, we insert elements from the **original pend** (`[7, 3, 2, 5, 6, 1, 10, 4, 13, 16]`) into the sorted **main**, using the same **Jacobsthal sequence**.

After inserting all elements correctly:

**Final Sorted List**:  
**[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]**  

---

## **Final Summary**  
✅ **Step 1:** Create pairs and sort within each pair  
✅ **Step 2:** Extract the larger numbers into "main" and the smaller ones into "pend"  
✅ **Step 3:** Recursively sort "main", generating a new "pend from recursion"  
✅ **Step 4:** Use Jacobsthal sequence to insert "pend from recursion" into the sorted main  
✅ **Step 5:** Finally, insert the original "pend" into the sorted main  
✅ **Final Step:** The list is fully sorted!  

---


