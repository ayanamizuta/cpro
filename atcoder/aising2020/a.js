setTimeout(() => {
    f()
},1000)


await new Promise(resolve => setTimeout(resolve, 1000));
f()