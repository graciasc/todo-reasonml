type todo = {
  name: string,
  id: int,
};
[@react.component]
let make = () => {
  let (input, setInput) = React.useState(() => "");
  // ml langs have array
  let (todos, setTodo) = React.useState(() => [||]);

  <div>
    <h1> {React.string("TODO App")} </h1>
    <input
      value=input
      type_="text"
      placeholder="add to todo"
      onChange={evt => {
        let newValue = React.Event.Form.target(evt)##value;
        setInput(_ => newValue);
      }}
    />
    <button
      onClick={_e => {
        let newTodo = {name: input, id: 1};
        setInput(_ => "");
        let updatedTodos = Array.append(todos, [|newTodo|]);
        setTodo(_ => updatedTodos);
      }}>
      {React.string("Add Todo")}
    </button>
    <ul>
      {todos
       |> Array.map(todo =>
            <li key={string_of_int(todo.id)}> {React.string(todo.name)} </li>
          )
       //|> Array.of_list  // Convert list to array
       |> React.array}
    </ul>
  </div>; // Convert array to React.element
};
