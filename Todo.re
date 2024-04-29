type todo = {
  name: string,
  id: int,
};

// in the ocaml documentation
let filterArray = (~f, arr) =>
  arr |> ArrayLabels.to_list |> ListLabels.filter(~f) |> ArrayLabels.of_list;

[@react.component]
let make = () => {
  let (input, setInput) = React.useState(() => "");
  // ml langs have array
  let (todos, setTodo) = React.useState(() => [||]);

  <div>
    <h1 style={ReactDOM.Style.make(~color="red", ())}>
      {React.string("TODO App")}
    </h1>
    <input
      value=input
      type_="text"
      placeholder="add to todo"
      onChange={evt => {
        //Js.log(evt);
        let newValue = React.Event.Form.target(evt)##value;
        setInput(_ => newValue);
      }}
    />
    <button
      onClick={_e => {
        // find array length
        let newTodo = {name: input, id: Array.length(todos)};

        setInput(_ => "");
        let updatedTodos = Array.append(todos, [|newTodo|]);
        setTodo(_ => updatedTodos);
      }}>
      {React.string("Add Todo")}
    </button>
    <ul>
      {todos
       |> Array.map(todo =>
            <li
              onClick={_ => {
                let newTodos = filterArray(~f=t => t.id !== todo.id, todos);
                setTodo(_ => newTodos);
              }}
              key={string_of_int(todo.id)}>
              {React.string(todo.name)}
            </li>
          )
       //|> Array.of_list  // Convert list to array
       |> React.array}
    </ul>
  </div>; // Convert array to React.element
};
