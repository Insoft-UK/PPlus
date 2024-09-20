<img src="https://raw.githubusercontent.com/Insoft-UK/PrimePlus/main/assets/P+_Logo.svg" style="width: 128px" />
P+ is a proprietary programming language designed to mitigate the challenges associated with code maintenance and comprehensibility in the HP Programming Language (PPL). P+ serves as an intermediary language that addresses these issues by introducing support for substitutions and facilitating code organization. The final output is a PPL program file with a minimal footprint, optimized to conserve the limited storage space available on the HP Prime.
<br/><br/>
P+ is essentially the PPL language with additional features, such as substitution capabilities, and requires all keywords to be in lowercase.
<br/><br/>
<b>Variable & Constant</b>
<br/>
Using longer, more meaningful variable and function names can enhance code readability and ease maintenance. However, when targeting the HP Prime's PPL (Programming Language) with UTF16-LE text-based files, employing lengthy names can lead to larger .hpprgm files, which poses a downside. This is where substitution proves beneficial in P+.
<br/><br/>
The <b>var</b> keyword is the subtitution for PPL code for `LOCAL`

> [!NOTE]
Please look at using **PPL Minifier** to handle long names in some situations.
>
```
var a:indexA;
const b:indexB := 1;
indexA += indexB; // Using subtitution.
a := a+b; // PPL results in a smaller .hpprgm file.
```


**for...next**
```
var I:index
for index := 0; index<10; index++ do
    // statement/s
next;
```

**do...loop**
The **do...loop** is simply a form of subtitution for PPL code for `WHILE 1 DO ... END;`
```
do
    // statement/s
loop;
```


**if** _condition_ **then** _statement/s_ **else** _statement/s_ **endif**
```
var e:hasError = true;
if hasError == true then
    // statement/s
else
    // statement/s
endif;
```
> [!TIP]
Also in P+ the use of `≤` `≠` and `≥` for `<=` `!=` and `>=` is also optional as the pre-processor will automatically covert any `<=` `!=` or `>=` to `≤` `≠` and `≥` PPL style.

> [!NOTE]
While **end** can be used in place of **endif**, by using **endif** helps in idetifing it's the end of a if statement.


**while...wend**
```
var r:isRunning := true
while isRunning == true do
    // statement/s
    isRunning := false;
wend;
```
> [!NOTE]
While **end** can be used in place of **wend**, by using **wend** helps in idetifing it's the end of a while loop.


**try** _condition_ **catch** _statement/s_ [**else** _statement/s_] **end**
```
try
    // statement/s
catch
    // statement/s
else
    // statement/s
end;
```


**(** _condition_ **?** _true_ **:** _false_**)**
```
var a:myValue := 0;
a := (X>Y ? 1 : 0);
```


**def eval:... name(...);**
```
var auto:alpha;
/// It is necessary to evaluate, as we are referencing a defined alias 'alpha' in the definition.
def eval:alpha := a setAlpha(a);
setAlpha(50.0);
```


**#pragma**
```
// Turn off C style bitwise operators ! ^ can now be used as math operations.
#pragma ( bitwise 0 )
```


**Pre-Calc**
```
#define SCREEN_WIDTH 320
local a := #[SCREEN_WIDTH / #[8 - 6]];
// PPL LOCAL a:=160;
local b := #[SCREEN_WIDTH / 4];
b := #[SCREEN_WIDTH / 2]:2; // Pre-Calc #[]:scale
// PPL b := 160.00;
```


> [!IMPORTANT]
In P+ `=` is treated as `:=` were in PPL `=` is treated as `==`

>[!NOTE]
The P+ proprietary programming language is susceptible to change, while also maintaining full compatibility with previous versions.
