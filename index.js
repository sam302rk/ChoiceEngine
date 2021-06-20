const menu_buttons = [{
        id: "#run",
        onclick: () => {
            $("#filestitle").show()

            let a = "";

            objects.forEach(e => {
                if (e.type === "CHAPTER") {
                    a += template.replace("CONTENT", `[${e.type}]\nname=${e.name}\nsubtitle=${e.subtitle}\nvisible=${e.visible}`);
                } else if (e.type === "DIALOG") {
                    a += template.replace("CONTENT", `[${e.type}]\nauthor=${e.author}\ntext=${e.text}\noptions=${e.options}`);
                }
            })

            $("#results").html(a)
        }
    },
    {
        id: "#add-file",
        onclick: () => {
            console.log("")
        }
    },
    {
        id: "#remove-file",
        onclick: () => {
            console.log("")
        }
    }
]

const template = "<div class=\"window\"><pre><code>CONTENT</code></pre></div>";

let objects = [
    { type: "CHAPTER", name: "Chapter 01", subtitle: "The Beginning", visible: false },
    { type: "DIALOG", author: "NPC", text: "Hello Player", options: "option1|option2|option3" }
]


$("#filestitle").hide()

menu_buttons.forEach(e => $(e.id).click(e.onclick))