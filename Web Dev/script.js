const nameInput = document.getElementById('name');
const passwordInput = document.getElementById('password');
const form = document.querySelector('.form');

form.addEventListener('submit', (event) => {
  event.preventDefault();

  let isValid = true;

  // Validate name
  if (nameInput.value.length >= 6 && nameInput.validity.valid) {
    isValid = false;
    nameInput.classList.add('invalid');
    alert('Name should contain only alphabets and be at least 6 characters long.');
  } else {
    nameInput.classList.remove('invalid');
  }

  // Validate password
  if (passwordInput.value.length < 6) {
    isValid = false;
    passwordInput.classList.add('invalid');
    alert('Password should be at least 6 characters long.');
  } else {
    passwordInput.classList.remove('invalid');
  }

  if (isValid) {
    // Submit the form
    form.submit();
  }
});