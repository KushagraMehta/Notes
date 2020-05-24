# JavaScript Fundamentals

## Data types

- **Number** for numbers of any kind: integer or floating-point, integers are limited by ±253.

  Besides regular numbers, there are so-called “special numeric values” which also belong to this data type: _Infinity_, _-Infinity_ and _NaN_.

- **Bigint** is for integer numbers of arbitrary length.
  A BigInt value is created by appending _n_ to the end of an integer:
- **String** for strings. A string may have zero or more characters, there’s no separate single-character type.

  In JavaScript, there are 3 types of quotes.

  1. **Double quotes**: "Hello".
  2. **Single quotes**: 'Hello'.
  3. **Backticks**: \`Hello`.
     Backticks are “extended functionality” quotes. They allow us to embed variables and expressions into a string by wrapping them in \${…}

- **Boolean** for true/false.
- **Null** for unknown values – a standalone type that has a single value null.
- **Undefined** for unassigned values – a standalone type that has a single value undefined.
- **Object** for more complex data structures.
- **Symbol** for unique identifiers.

## Type Conversions

### String Conversion

**String(value)** function to convert a value to a string

### Numeric Conversion

Numeric conversion happens in mathematical functions and expressions automatically.

| Value          | Becomes…                                                                                                                                                               |
| -------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| undefined      | NaN                                                                                                                                                                    |
| null           | 0                                                                                                                                                                      |
| true and false | 1 and 0                                                                                                                                                                |
| string         | Whitespacesfrom the start and end are removed. If the remaining string is empty, the result is 0. Otherwise, the number is “read” from the string. An error gives NaN. |

> The plus + exists in two forms: the binary form and the unary form. The unary plus or, in other words, the plus operator + applied to a single value, doesn’t do anything to numbers. But if the operand is not a number, the unary plus converts it into a number. It actually does the same thing as _Number(...)_, but is shorter.

### == v/s ===

Equality v/s Strict equality.

A strict equality operator === checks the equality without type conversion.

### Breaking the loop

```js
labelName: for (...) {
  ...
  .. break labelName;
  ...
}
```

### Function

A function with an empty return or without it returns undefined
Never add a newline between return and the value

> ⚠ For a long expression in return, it might be tempting to put it on a separate line, like this:
>
> ```js
> return;
> some + long + expression + or + whatever * f(a) + f(b);
> ```
>
> That doesn’t work, because JavaScript assumes a semicolon after return. That’ll work the same as:
>
> ```js
> return;
> some + long + expression + or + whatever * f(a) + f(b);
> ```
>
> So, it effectively becomes an empty return.
> If we want the returned expression to wrap across multiple lines, we should start it at the same line as return. Or at least put the opening parentheses there as follows:
>
> ```js
> return some + long + expression + or + whatever * f(a) + f(b);
> ```
>
> And it will work just as we expect it to.

**Function Expression** v/s **Function Declaration**

**Function Expression**

```js
let name = function(){
    ...
};
```

**Function Declaration**

```js
function name(){
    ...
}
```

1. Created by the JavaScript engine.
   - A Function Expression is created when the execution reaches it and is usable only from that moment.
   - A Function Declaration can be called earlier than it is defined.
2. Block scope.
   - In strict mode, when a Function Declaration is within a code block, it’s visible everywhere inside that block. But not outside of it.

---

# Object

Objects are used to store keyed collections of various data and more complex entities. In JavaScript, objects penetrate almost every aspect of the language. So we must understand them first before going in-depth anywhere else.

An object can be created with figure brackets {…} with an optional list of properties. A property is a “key: value” pair, where key is a string (also called a “property name”), and value can be anything.

We can imagine an object as a cabinet with signed files. Every piece of data is stored in its file by the key. It’s easy to find a file by its name or add/remove a file.
