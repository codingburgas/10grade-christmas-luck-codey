import './App.css';

export default function App() {
  return (
    <>
      <div className="flex flex-col items-center justify-center">
        <img className="h-[46.5rem] w-[1500px] select-none mb-10" src="./src/assets/backgroundImage.png" alt="Background Image" />
        <h1 className="text-[6.5vw] absolute mb-52 font-bold font-body text-transparent" style={{ WebkitTextStrokeWidth: '1.2px', WebkitTextStrokeColor: '#000', }}>Codey</h1>
        <h1 className="absolute text-[1.1vw] mb-14 font-body">Online library that allows people to show their work with the world.</h1>
        <h1 className="underline absolute mt-8 text-[1.5vw] font-bold font-body"><a href="https://github.com/codingburgas/10grade-christmas-luck-codey" target='_blank'>Check us out</a></h1>
      </div>
      <img className="w-[100vw] h-[7vh] select-none" src="./src/assets/separator.png" alt="Separator" />
      <div className="flex items-center justify-center h-[15vh] px-4 mt-40">
        <img
          className="h-[5vw] mx-4"
          src="./src/assets/stars.png"
          alt="Left Star"
        />
        <p className="text-center text-black text-[1.3vw] font-light font-body max-w-[52%] leading-snug">
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

      <div className="flex justify-center items-center py-48 font-body">
        <img src='./src/assets/leftArrow.png' className='absolute mt-96 left-0' />
        <div className="rounded-[30px] border-[1px] border-[#191A23] bg-white shadow-[0px_5px_0px_0px_#191A23] w-[25vw] h-[63vh] p-8 mx-10">
          <h2 className="text-[2.3vw] font-bold">Be a</h2>
          <h3 className="text-[2.3vw] font-bold text-[#d0d838]">Reader</h3>
          <p className="mt-6 text-[1.3vw]">
            By choosing this role, you unlock incredible perks like:
          </p>
          <ul className="list-disc pl-6 text-[1.3vw]">
            <li>Discover new authors</li>
            <li>Connect with our friendly community</li>
            <li>Keep up with your favorite author’s work</li>
          </ul>
          <p className="mt-6 text-[1.3vw] underline text-[#000] cursor-pointer">And more!</p>
        </div>
        <img src='./src/assets/rightArrow.png' className='absolute mt-2 right-0' />
        <div className="rounded-[30px] border-[1px] border-[#191A23] bg-white shadow-[0px_5px_0px_0px_#191A23] w-[25vw] h-[63vh] p-8 mx-10">
          <h2 className="text-[2.3vw] font-bold">Be a</h2>
          <h3 className="text-[2.3vw] font-bold text-[#d0d838]">Writer</h3>
          <p className="mt-6 text-[1.3vw]">
            By choosing this role, you unlock incredible perks like:
          </p>
          <ul className="list-disc pl-6 text-[1.3vw]">
            <li>Share your stories</li>
            <li>Build a fanbase</li>
            <li>Connect with fellow writers</li>
          </ul>
          <p className="mt-6 text-[1.3vw] underline text-[#000] cursor-pointer">And more!</p>
        </div>
      </div>

      <div className="flex flex-col items-center justify-center py-16 font-body">
        <h1 className="text-center text-[2rem] font-bold leading-relaxed">
          The Ultimate Platform For <span className="underline"> Discovering Stories</span> And <br />
          <span className="underline">Sharing Your Creativity</span> With The World.
        </h1>

        <img
          className="my-6 w-[18rem] select-none"
          src="./src/assets/feedbackStars.png"
        />

        <img
          className="mb-[-1rem] mt-[-2.5rem] w-[35rem] select-none"
          src="./src/assets/laptop.png"
          alt="Laptop"
        />

        <p className="text-center font-light text-[1.2rem] px-4 max-w-[45vw]">
          We are creating a vibrant platform where creativity meets community. Discover amazing authors, dive into captivating stories, or share your own works with the world. Whether you're a reader seeking inspiration or a writer ready to shine, Codey is the perfect place to connect, create, and grow!
        </p>

        <button className="mt-10 bg-white text-black text-[1.5rem] font-bold px-12 py-4 rounded-full border border-black shadow-[0px_5px_0px_0px_#191A23] 
        hover:shadow-none hover:scale-105 hover:bg-black hover:text-white transition-all duration-300 ease-in-out">
          Download
        </button>
      </div>
    </>
  );
}
