import './App.css';

export default function App() {
  return (
    <>
      <div className="flex flex-col items-center justify-center">
        <img className="h-[46.5rem] w-[1500px] select-none mb-10" src="./src/assets/backgroundImage.png" alt="Background Image" />
        <h1 className="text-[6.5vw] absolute mb-52 font-bold font-body text-transparent" style={{ WebkitTextStrokeWidth: '1.2px', WebkitTextStrokeColor: '#000', }}>Codey</h1>
        <h1 className="absolute text-[1.1vw] mb-14 font-body">Online library that allows people to show their work with the world.</h1>
        <h1 className="underline absolute mt-8 text-[1.5vw] font-bold font-body">Check us out</h1>
      </div>
      <img className="w-[100vw] h-[7vh] select-none" src="./src/assets/separator.png" alt="Separator" />
      <div className="flex items-center justify-center h-[15vh] px-4 mt-20">
        <img
          className="h-[5vw] mx-4"
          src="./src/assets/stars.png"
          alt="Left Star"
        />
        <p className="text-center text-black text-[1.2vw] font-light font-body max-w-[52%] leading-snug">
          Don’t be afraid to step out of your comfort zone and try something
          new—Codey is the perfect place to explore your creativity. Whether
          you're writing your first story or discovering new authors, every
          adventure starts with a single step!
        </p>
        <img
          className="h-[5vw] mx-4"
          src="./src/assets/stars.png"
          alt="Right Star"
        />
      </div>
    </>
  );
}
